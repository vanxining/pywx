/***************************************************************
 * Name:      PyBind.hxx
 * Purpose:   Python 事件处理辅助设施
 * Author:    Wang Xiaoning (vanxining@139.com)
 * Created:   2014
 **************************************************************/
#pragma once
#include "wx/event.h"

#ifndef __GCCXML__
#   include "../Gen/_PySelf.hxx"
#else
    class _PySelf {};
    class PyObject;
#endif

//////////////////////////////////////////////////////////////////////////////

class wxPyEventType;

/// 将某事件绑定/解绑某个 Python callable

void wxPyBind
   (wxEvtHandler *p, 
    int event, 
    PyObject *callable, 
    int id = -1, 
    int lastId = -1, 
    wxObject *userData = nullptr);

void wxPyBind
   (wxEvtHandler *p, 
    const wxPyEventType &event, 
    PyObject *callable, 
    int id = -1, 
    int lastId = -1,
    wxObject *userData = nullptr);

bool wxPyUnbind
   (wxEvtHandler *p, 
    int event, 
    PyObject *callable, 
    int id = -1, 
    int lastId = -1,
    wxObject *userData = nullptr);

bool wxPyUnbind
   (wxEvtHandler *p, 
    const wxPyEventType &event, 
    PyObject *callable, 
    int id = -1, 
    int lastId = -1,
    wxObject *userData = nullptr);


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// These Event classes can be derived from in Python and passed through the
// event system without loosing anything. They do this by keeping a reference
// to themselves and some special case handling in wxPyCallback::EventThunker.

class wxPyEvent : public wxEvent, public _PySelf {
public:
    wxPyEvent(int winid = 0, wxEventType commandType = wxEVT_NULL);
    wxPyEvent(const wxPyEvent &other);

    virtual wxEvent *Clone() const {
        return new wxPyEvent(*this);
    }

private:

    wxPyEvent &operator=(const wxPyEvent &);
    DECLARE_DYNAMIC_CLASS(wxPyEvent)
};

class wxPyCommandEvent : public wxCommandEvent, public _PySelf {
public:
    wxPyCommandEvent(wxEventType commandType = wxEVT_NULL, int id = 0);
    wxPyCommandEvent(const wxPyCommandEvent &other);

    virtual wxEvent *Clone() const {
        return new wxPyCommandEvent(*this);
    }

private:

    wxPyCommandEvent &operator=(const wxPyCommandEvent &);
    DECLARE_DYNAMIC_CLASS(wxPyCommandEvent)
};

/// 用于实现 Python 自定义事件
class wxPyEventType {
public:

    /// 构造函数
    wxPyEventType(wxEventType id, bool isCommandEvent);
    
    wxEventType GetEventType() const {
        return m_id;
    }

    /// 是否命令事件(一直传递到父窗口)
    bool IsCommandEvent() const {
        return m_isCommandEvent;
    }

private:

    wxEventType m_id;
    bool m_isCommandEvent;
};

/// 返回一个新的事件类型
wxPyEventType wxPyNewEventType(bool isCommandEvent);
