/***************************************************************
 * Name:      PyApp.cxx
 * Purpose:   wxApp °ü¹üÆ÷
 * Author:    Wang Xiaoning (vanxining@139.com)
 * Created:   2014-01
 **************************************************************/
#include "StdAfx.hpp"

#include "../Gen/_Python.hxx" // Let it be the first.

#include "PyApp.hxx"

#include "../Gen/_Common.hxx"

#ifdef __WXGTK__
#   include <gdk/gdkx.h>
#   include <gtk/gtk.h>
#   include <wx/gtk/private/win_gtk.h>
#endif

#ifdef __WXMAC__
#   include <wx/osx/private.h>
#endif

#ifdef __WXMSW__
#   include <wx/msw/private.h>
#   include <wx/msw/winundef.h>
#   include <wx/msw/msvcrt.h>
#endif

#include <cstdio> // For fprintf(), stderr

#ifdef __WXMSW__

#if PY_MAJOR_VERSION < 3

#pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' "\
                        " version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' "\
                        " language='*'\"")

HANDLE g_act_ctx_handle = INVALID_HANDLE_VALUE;
ULONG_PTR g_act_ctx_cookie = 0;

static void ReportLastError(const char *func_name) {
    char buf[256];
    FormatMessageA(
        FORMAT_MESSAGE_FROM_SYSTEM,
        nullptr,
        GetLastError(),
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        buf,
        256,
        nullptr
    );

    printf("[%s] %s\n", func_name, buf);
}

static void EnableVisualStyles() {
    ACTCTX act_ctx;
    ZeroMemory(&act_ctx, sizeof(act_ctx));
    act_ctx.cbSize = sizeof(act_ctx);
    act_ctx.hModule = wxGetInstance();
    act_ctx.lpResourceName = MAKEINTRESOURCE(2);
    act_ctx.dwFlags = ACTCTX_FLAG_HMODULE_VALID | ACTCTX_FLAG_RESOURCE_NAME_VALID;

    g_act_ctx_handle = CreateActCtx(&act_ctx);
    if (g_act_ctx_handle != INVALID_HANDLE_VALUE) {
        if (ActivateActCtx(g_act_ctx_handle, &g_act_ctx_cookie)) {
            return;
        }
    }

    ReportLastError(__FUNCTION__);
}

static void DisableVisualStyles() {
    if (!DeactivateActCtx(0, g_act_ctx_cookie)) {
        ReportLastError(__FUNCTION__);
    }

    ReleaseActCtx(g_act_ctx_handle);

    g_act_ctx_cookie = 0;
    g_act_ctx_handle = INVALID_HANDLE_VALUE;
}

#endif

//----------------------------------------------------------------------
// This gets run when the DLL is loaded.  We just need to save the
// instance handle.
//----------------------------------------------------------------------

extern "C"
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
    // If wxPython is embedded in another wxWidgets app then
    // the instance has already been set.
    if (!wxGetInstance()) {
        wxSetInstance(hinstDLL);
    }

    return TRUE;
}

#endif  // __WXMSW__

IMPLEMENT_ABSTRACT_CLASS(wxPyApp, wxApp);

wxPyApp::wxPyApp()
    : m_startup_completed(false), m_argv(nullptr) {
#if defined(__WXMSW__) && PY_MAJOR_VERSION < 3
    EnableVisualStyles();
#endif
}

wxPyApp::~wxPyApp() {
    if (m_argv) {
        int i = 0;
        while (arg_char_type *arg = m_argv[i++]) {
#if PY_MAJOR_VERSION >= 3
            delete [] arg;
#else
            free(arg);
#endif
        }

        delete [] m_argv;
        m_argv = nullptr;
    }

#if defined(__WXMSW__) && PY_MAJOR_VERSION < 3
    DisableVisualStyles();
#endif
}

void wxPyApp::SetStartupComplete(bool complete) {
    m_startup_completed = complete;
}

void wxPyApp::_BootstrapApp() {
    static bool s_initialized = false;
    bool result = false;

    // Only initialize wxWidgets once.
    if (!s_initialized) {
        // Copy the values in Python's sys.argv list to a C array to
        // be passed to the wxEntryStart function below.

        int argc = 0;
        {
            PBPP_NEW_THREAD_BLOCKER

            PyObject *sys_argv = PySys_GetObject("argv");
            if (sys_argv != nullptr) {
                argc = PyList_Size(sys_argv);
                m_argv = new arg_char_type *[argc + 1];

                for (int i = 0; i < argc; i++) {
                    PyObject *py_arg = PyList_GetItem(sys_argv, i); // Borrowed reference
                    // If there isn't anything in sys.argv[0] then set it to the Python executable.
                    if (i == 0 && PyObject_Size(py_arg) < 1) {
                        py_arg = PySys_GetObject("executable");
                    }
#if PY_MAJOR_VERSION >= 3
                    Py_ssize_t len = PyObject_Size(py_arg);
                    if (len > 0) {
                        m_argv[i] = new arg_char_type[len + 1];
                        PyUnicode_AsWideChar(py_arg, m_argv[i], len + 1);
                    } else {
                        m_argv[i] = nullptr;
                    }
#else
                    m_argv[i] = _strdup(PyBytes_AsString(py_arg));
#endif
                }

                m_argv[argc] = nullptr;
            }
        }

        // Initialize wxWidgets.
#ifdef __WXOSX__
        wxMacAutoreleasePool autoreleasePool;
#endif
        result = wxEntryStart(argc, m_argv);
        // wxApp takes ownership of the argv array, don't delete it here.

        if (!result) {
            PBPP_NEW_THREAD_BLOCKER
            PyErr_SetString(PyExc_SystemError,
                "wxEntryStart failed, unable to initialize wxWidgets!"
#ifdef __WXGTK__
                "  (Is DISPLAY set properly?)"
#endif
                );

            goto __ERR;
        }

        Py_AtExit(wxEntryCleanup);

        s_initialized = true;
    } else {
        wxApp::argc = 0;
    }

    // It's now ok to generate exceptions for assertion errors.
    SetStartupComplete(true);

    // Call the Python wxApp's OnInit function if it exists.
    result = OnInit();

    if (!result) {
        PyErr_SetString(PyExc_SystemExit, "OnInit() returned False, exiting...");
    }

__ERR:
    return;
}

int wxPyApp::MainLoop() {
    int retval = 0;

    {
#ifdef __WXOSX__
        wxMacAutoreleasePool autoreleasePool;
#endif
        DeletePendingObjects();
    }

    bool initialized = wxTopLevelWindows.GetCount() != 0;
    if (initialized) {
        if (m_exitOnFrameDelete == Later) {
            m_exitOnFrameDelete = Yes;
        }

        retval = wxApp::MainLoop();
        OnExit();
    } else {
        fprintf(stderr, "[wxPyApp::MainLoop] Why? No top level windows...\n");
    }

    return retval;
}

// Function to test if the Display (or whatever is the platform equivallent)
// can be connected to.
bool wxPyApp::IsDisplayAvailable() {
#ifdef __WXGTK__
    Display *display;
    display = XOpenDisplay(nullptr);
    if (display == nullptr) {
        return false;
    }
    XCloseDisplay(display);
    return true;
#endif

#ifdef __WXMAC__
    // This is adapted from Python's Mac/Modules/MacOS.c in the
    // MacOS_WMAvailable function.
    bool rv;
    ProcessSerialNumber psn;

    /*
    ** This is a fairly innocuous call to make if we don't have a window
    ** manager, or if we have no permission to talk to it. It will print
    ** a message on stderr, but at least it won't abort the process.
    ** It appears the function caches the result itself, and it's cheap, so
    ** no need for us to cache.
    */
#ifdef kCGNullDirectDisplay
    /* On 10.1 CGMainDisplayID() isn't available, and
    ** kCGNullDirectDisplay isn't defined.
    */
    if (CGMainDisplayID() == 0) {
        rv = false;
    } else
#endif
    {
        // Also foreground the application on the first call as a side-effect.
        if (GetCurrentProcess(&psn) < 0 || SetFrontProcess(&psn) < 0) {
            rv = false;
        } else {
            rv = true;
        }
    }
    return rv;
#endif

#ifdef __WXMSW__
    // TODO...
    return true;
#endif
}

wxPyApp* wxGetApp() {
    return (wxPyApp *) wxTheApp;
}
