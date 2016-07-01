/***************************************************************
 * Name:      PyApp.cxx
 * Purpose:   wxApp ������
 * Author:    Wang Xiaoning (vanxining@139.com)
 * Created:   2014-1
 **************************************************************/
#include "StdAfx.hpp"

#include "PyApp.hxx"
#include "../Gen/_Python.hxx"
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

#ifdef __WXMSW__             // If building for Windows...

#if defined(_WINDLL)
#   pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' "\
                           " version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' "\
                           " language='*'\"")
#endif // __WXMSW__

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

wxPyApp::wxPyApp() : m_startupCompleted(false), m_argv(nullptr) {}

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
}

void wxPyApp::SetStartupComplete(bool complete) {
    m_startupCompleted = complete;
}

#define __SCOPE__()

void wxPyApp::_BootstrapApp() {
    static bool haveInitialized = false;
    bool        result;

    // Only initialize wxWidgets once
    if (!haveInitialized) {
        // Copy the values in Python's sys.argv list to a C array to
        // be passed to the wxEntryStart function below

        int argc = 0;

        __SCOPE__() {
            PBPP_NEW_THREAD_BLOCKER

            PyObject *sysargv = PySys_GetObject("argv");
            if (sysargv != nullptr) {
                argc = PyList_Size(sysargv);
                m_argv = new arg_char_type*[argc + 1];

                for (int x = 0; x < argc; x++) {
                    PyObject *py_arg = PyList_GetItem(sysargv, x); // Borrowed reference
                    // If there isn't anything in sys.argv[0] then set it to the Python executable
                    if (x == 0 && PyObject_Length(py_arg) < 1) {
                        py_arg = PySys_GetObject("executable");
                    }
#if PY_MAJOR_VERSION >= 3
                    int len = PyObject_Length(py_arg);
                    m_argv[x] = new arg_char_type[len + 1];
                    wxPyUnicode_AsWideChar(py_arg, m_argv[x], len + 1);
#else
                    m_argv[x] = _strdup(PyBytes_AsString(py_arg));
#endif
                }

                m_argv[argc] = nullptr;
            }
        }

        // Initialize wxWidgets
#ifdef __WXOSX__
        wxMacAutoreleasePool autoreleasePool;
#endif
        result = wxEntryStart(argc, m_argv);
        // wxApp takes ownership of the argv array, don't delete it here

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

        // HiDPI
        void wxSetProcessDPIAware();
        wxSetProcessDPIAware();

        Py_AtExit(wxEntryCleanup);

        haveInitialized = true;
    }
    else {
        wxApp::argc = 0;
    }

    // It's now ok to generate exceptions for assertion errors
    SetStartupComplete(true);

    // Call the Python wxApp's OnInit function if it exists
    result = OnInit();

    if (!result) {
        PyErr_SetString(PyExc_SystemExit, "OnInit() returned False, exiting...");
    }

__ERR:
    return;
}

int wxPyApp::MainLoop() {
    int retval = 0;

    __SCOPE__() {
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
    }
    else {
        printf("[wxPyApp::MainLoop] Why? No top level windows...\n");
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
    }
    else
#endif
    {
        // Also foreground the application on the first call as a side-effect.
        if (GetCurrentProcess(&psn) < 0 || SetFrontProcess(&psn) < 0) {
            rv = false;
        }
        else {
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