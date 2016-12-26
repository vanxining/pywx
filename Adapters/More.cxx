//////////////////////////////////////////////////////////////////////////
// Name:      More.hxx
// Purpose:   对 wxWidgets 某些不合理接口的一些补充
// Author:    Wang Xiaoning (vanxining@139.com)
// Created:   2014-12-03
//////////////////////////////////////////////////////////////////////////
#include "StdAfx.hpp"

#include "More.hxx"
#include "../Gen/_Common.hxx"

#include <wx/mstream.h> // for wxMemoryOutputStream

//////////////////////////////////////////////////////////////////////////

PyObject * OutputStream_Write(wxOutputStream *outs, PyObject *bytes) {
    PyThreadBlocker blocker;

    bool ok = outs->WriteAll(PyString_AsString(bytes), PyString_Size(bytes));
    return PyBool_FromLong(ok ? 1 : 0);
}

PyObject *InputStream_Read(wxInputStream *ins) {
    wxMemoryOutputStream mos;
    ins->Read(mos);

    wxCharBuffer buf(mos.GetSize());
    mos.CopyTo(buf.data(), buf.length());

    PyThreadBlocker blocker;
    return PyUnicode_FromStringAndSize(buf.data(), buf.length());
}

PyObject *DropFilesEvent_GetFiles(wxDropFilesEvent *event) {
    const int n = event->GetNumberOfFiles();
    wxString *files = event->GetFiles();
    PyObject *list = PyList_New(n);

    for (int i = 0; i < n; i++) {
        PyObject *item = PyUnicode_FromWideChar(files[i].wx_str(), files[i].length());
        PyList_SET_ITEM(list, i, item);
    }

    return list;
}

void wxSetProcessDPIAware() {
#ifdef __WXMSW__
    typedef BOOL (WINAPI *SetProcessDPIAware_t)(void);
    HINSTANCE hDLL = ::LoadLibrary(L"user32.dll");
    SetProcessDPIAware_t pfnSetProcessDPIAware =
        (SetProcessDPIAware_t) ::GetProcAddress(hDLL, "SetProcessDPIAware");

    if (pfnSetProcessDPIAware) {
        pfnSetProcessDPIAware();
    }
#endif // __WXMSW__
}

PyObject *CharArrayToPyString(PyObject *py_text) {
    PyThreadBlocker blocker;

    char *text = "";

    if (py_text != Py_None) {
        if (PyObject_TypeCheck(py_text, &PyCapsule_Type)) {
            text = (char *) PyCapsule_GetPointer(py_text, "char *");
        }
    }

    return PyUnicode_FromString(text);
}
