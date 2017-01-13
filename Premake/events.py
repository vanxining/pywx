# -*- coding: gb2312 -*- 

import sys
import re


header = '''/***************************************************************
 * Name:      PyBind.cxx
 * Purpose:   Python 事件处理辅助设施
 * Author:    Wang Xiaoning (vanxining@139.com)
 * Created:   2014
 **************************************************************/
#include "StdAfx.hpp"

#include "PyBind.hxx"
#include "../Gen/_Python.hxx"
#include "../Gen/_Common.hxx"

#include "wx/listctrl.h"
#include "wx/treectrl.h"
#include "wx/notebook.h"
#include "wx/process.h"

//////////////////////////////////////////////////////////////////////////

#define BEGIN_PYEVENT_MAP()

#define PYEVENT(tag) if (event == tag) { \\
    if (unbind) { \\
        ret = p->Unbind(tag, s_functor, id, lastId, userData); \\
    } else { \\
        p->Bind(tag, s_functor, id, lastId, userData); \\
    } \\
    \\
    s_functor.m_callable = nullptr; \\
    return ret; \\
}

#define END_PYEVENT_MAP() \\
    PyErr_SetString(PyExc_TypeError, "No corresponding C++ event class type defined for this event tag."); \\
    PyErr_Print(); \\
    return false;

//////////////////////////////////////////////////////////////////////////

namespace {

struct Functor {
    PyObject *m_callable = nullptr;

public:

    Functor() {}

    Functor(const Functor &other) {
        m_callable = other.m_callable;

        PBPP_NEW_THREAD_BLOCKER
        Py_INCREF(m_callable);
    }
    
    ~Functor() {
        if (m_callable) {
            PBPP_NEW_THREAD_BLOCKER
            Py_DECREF(m_callable);
            m_callable = nullptr;
        }
    }

    Functor &operator=(const Functor &other) = delete;
    bool operator==(const Functor &other) const = delete;

private:
    
    void DoCall(PyObject *py_event) {
        PyObject *res = PyObject_CallFunctionObjArgs(m_callable, py_event, NULL);
        if (!res) {
            PyErr_Print();
        }
    }

public:

    void operator()(wxPyEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        DoCall(e.GetSelf());
    }

    void operator()(wxPyCommandEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        DoCall(e.GetSelf());
    }'''

operator_overload = '''
    void operator()(%(CLS)s &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__%(CLS_NO_PREFIX)s(const %(CLS)s &);
        PyObject *py_event = Borrow__%(CLS_NO_PREFIX)s(e);
        DoCall(py_event);
    }'''

tail = '''};

}

//////////////////////////////////////////////////////////////////////////

bool DoPyBind
(wxEvtHandler *p, wxEventType event, PyObject *callable, int id, int lastId, 
 wxObject *userData, bool unbind) {
    PBPP_NEW_THREAD_BLOCKER

    static Functor s_functor;
    s_functor.m_callable = callable;
    bool ret = true;

    BEGIN_PYEVENT_MAP()
'''

tail_more = '''
    END_PYEVENT_MAP()
}

bool DoPyBind
(wxEvtHandler *p, const wxPyEventType &event, PyObject *callable, 
 int id, int lastId, wxObject *userData, bool unbind) {
    PBPP_NEW_THREAD_BLOCKER

    static Functor s_functor;
    s_functor.m_callable = callable;
    bool ret = true;
    
    if (event.IsCommandEvent()) {
        wxEventTypeTag<wxPyCommandEvent> tag(event.GetEventType());
        if (unbind) {
            ret = p->Unbind(tag, s_functor, id, lastId, userData);
        } else {
            p->Bind(tag, s_functor, id, lastId, userData);
        }
    } else {
        wxEventTypeTag<wxPyEvent> tag(event.GetEventType());
        if (unbind) {
            ret = p->Unbind(tag, s_functor, id, lastId, userData);
        } else {
            p->Bind(tag, s_functor, id, lastId, userData);
        }
    }

    s_functor.m_callable = nullptr;
    return ret;
}

void wxPyBind(wxEvtHandler *p, wxEventType event, PyObject *callable, int id, int lastId, wxObject *userData) {
    DoPyBind(p, event, callable, id, lastId, userData, false);
}

void wxPyBind(wxEvtHandler *p, const wxPyEventType &event, PyObject *callable, int id, int lastId, wxObject *userData) {
    DoPyBind(p, event, callable, id, lastId, userData, false);
}

bool wxPyUnbind(wxEvtHandler *p, wxEventType event, PyObject *callable, int id, int lastId, wxObject *userData) {
    return DoPyBind(p, event, callable, id, lastId, userData, true);
}

bool wxPyUnbind(wxEvtHandler *p, const wxPyEventType &event, PyObject *callable, int id, int lastId, wxObject *userData) {
    return DoPyBind(p, event, callable, id, lastId, userData, true);
}

//////////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNAMIC_CLASS(wxPyEvent, wxEvent);
IMPLEMENT_DYNAMIC_CLASS(wxPyCommandEvent, wxCommandEvent);

wxPyEvent::wxPyEvent(int winid, wxEventType commandType)
    : wxEvent(winid, commandType) {}

wxPyEvent::wxPyEvent(const wxPyEvent &other)
    : wxEvent(other) {
    SetSelf(other.m_self, true);
}

wxPyCommandEvent::wxPyCommandEvent(wxEventType commandType, int id)
    : wxCommandEvent(commandType, id) {}

wxPyCommandEvent::wxPyCommandEvent(const wxPyCommandEvent &other)
    : wxCommandEvent(other) {
    SetSelf(other.m_self, true);
}

//////////////////////////////////////////////////////////////////////////

wxPyEventType::wxPyEventType(wxEventType id, bool isCommandEvent)
    : m_id(id), m_isCommandEvent(isCommandEvent) {}

wxPyEventType wxPyNewEventType(bool isCommandEvent) {
    return wxPyEventType(wxNewEventType(), isCommandEvent);
}'''


tags = []
cpp_event_classes = set()

# 注意模式中的前导空格
for r in re.finditer(r"  wxDECLARE_EXPORTED_EVENT.+(wxEVT_\w+), (wx\w+)", open("E.txt").read()):
    tags.append(r.group(1))
    cpp_event_classes.add(r.group(2))


with open("../Adapters/PyBind.cxx", "w") as outf:
    sys.stdout = outf

    print(header)
    for cls in cpp_event_classes:
        print(operator_overload % {
            "CLS": cls,
            "CLS_NO_PREFIX": cls[2:],
        })

    print(tail)
    for tag in tags:
        print("        PYEVENT(%s)" % tag)

    print(tail_more)


with open("../Hacks/_EVENTTAGS.hxx", "w") as outf:
    sys.stdout = outf

    print('''#ifdef __CASTXML__
''')

    for tag in tags:
        print("extern int %s;" % tag)

    print("\n#endif")
