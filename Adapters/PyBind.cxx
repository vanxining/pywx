/***************************************************************
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
#include "wx/process.h"

//////////////////////////////////////////////////////////////////////////

#define BEGIN_PYEVENT_MAP()

#define PYEVENT(tag) if (event == tag) { \
    if (unbind) { \
        ret = p->Unbind(tag, s_functor, id, lastId, userData); \
    } \
    else { \
        p->Bind(tag, s_functor, id, lastId, userData); \
    } \
    \
    s_functor.m_callable = nullptr; \
    return ret; \
}

#define END_PYEVENT_MAP() \
    PyErr_SetString(PyExc_TypeError, "No corresponding C++ event class type defined for this event tag."); \
    PyErr_Print(); \
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
    }

    void operator()(wxKeyEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__KeyEvent(const wxKeyEvent &);
        PyObject *py_event = Borrow__KeyEvent(e);
        DoCall(py_event);
    }

    void operator()(wxMouseEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__MouseEvent(const wxMouseEvent &);
        PyObject *py_event = Borrow__MouseEvent(e);
        DoCall(py_event);
    }

    void operator()(wxSysColourChangedEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__SysColourChangedEvent(const wxSysColourChangedEvent &);
        PyObject *py_event = Borrow__SysColourChangedEvent(e);
        DoCall(py_event);
    }

    void operator()(wxWindowCreateEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__WindowCreateEvent(const wxWindowCreateEvent &);
        PyObject *py_event = Borrow__WindowCreateEvent(e);
        DoCall(py_event);
    }

    void operator()(wxQueryNewPaletteEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__QueryNewPaletteEvent(const wxQueryNewPaletteEvent &);
        PyObject *py_event = Borrow__QueryNewPaletteEvent(e);
        DoCall(py_event);
    }

    void operator()(wxSizeEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__SizeEvent(const wxSizeEvent &);
        PyObject *py_event = Borrow__SizeEvent(e);
        DoCall(py_event);
    }

    void operator()(wxDropFilesEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__DropFilesEvent(const wxDropFilesEvent &);
        PyObject *py_event = Borrow__DropFilesEvent(e);
        DoCall(py_event);
    }

    void operator()(wxAsyncMethodCallEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__AsyncMethodCallEvent(const wxAsyncMethodCallEvent &);
        PyObject *py_event = Borrow__AsyncMethodCallEvent(e);
        DoCall(py_event);
    }

    void operator()(wxJoystickEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__JoystickEvent(const wxJoystickEvent &);
        PyObject *py_event = Borrow__JoystickEvent(e);
        DoCall(py_event);
    }

    void operator()(wxUpdateUIEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__UpdateUIEvent(const wxUpdateUIEvent &);
        PyObject *py_event = Borrow__UpdateUIEvent(e);
        DoCall(py_event);
    }

    void operator()(wxScrollWinEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__ScrollWinEvent(const wxScrollWinEvent &);
        PyObject *py_event = Borrow__ScrollWinEvent(e);
        DoCall(py_event);
    }

    void operator()(wxScrollEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__ScrollEvent(const wxScrollEvent &);
        PyObject *py_event = Borrow__ScrollEvent(e);
        DoCall(py_event);
    }

    void operator()(wxEraseEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__EraseEvent(const wxEraseEvent &);
        PyObject *py_event = Borrow__EraseEvent(e);
        DoCall(py_event);
    }

    void operator()(wxTimerEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__TimerEvent(const wxTimerEvent &);
        PyObject *py_event = Borrow__TimerEvent(e);
        DoCall(py_event);
    }

    void operator()(wxMouseCaptureLostEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__MouseCaptureLostEvent(const wxMouseCaptureLostEvent &);
        PyObject *py_event = Borrow__MouseCaptureLostEvent(e);
        DoCall(py_event);
    }

    void operator()(wxListEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__ListEvent(const wxListEvent &);
        PyObject *py_event = Borrow__ListEvent(e);
        DoCall(py_event);
    }

    void operator()(wxPaletteChangedEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__PaletteChangedEvent(const wxPaletteChangedEvent &);
        PyObject *py_event = Borrow__PaletteChangedEvent(e);
        DoCall(py_event);
    }

    void operator()(wxPaintEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__PaintEvent(const wxPaintEvent &);
        PyObject *py_event = Borrow__PaintEvent(e);
        DoCall(py_event);
    }

    void operator()(wxCommandEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__CommandEvent(const wxCommandEvent &);
        PyObject *py_event = Borrow__CommandEvent(e);
        DoCall(py_event);
    }

    void operator()(wxNavigationKeyEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__NavigationKeyEvent(const wxNavigationKeyEvent &);
        PyObject *py_event = Borrow__NavigationKeyEvent(e);
        DoCall(py_event);
    }

    void operator()(wxFocusEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__FocusEvent(const wxFocusEvent &);
        PyObject *py_event = Borrow__FocusEvent(e);
        DoCall(py_event);
    }

    void operator()(wxIdleEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__IdleEvent(const wxIdleEvent &);
        PyObject *py_event = Borrow__IdleEvent(e);
        DoCall(py_event);
    }

    void operator()(wxTextUrlEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__TextUrlEvent(const wxTextUrlEvent &);
        PyObject *py_event = Borrow__TextUrlEvent(e);
        DoCall(py_event);
    }

    void operator()(wxTreeEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__TreeEvent(const wxTreeEvent &);
        PyObject *py_event = Borrow__TreeEvent(e);
        DoCall(py_event);
    }

    void operator()(wxThreadEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__ThreadEvent(const wxThreadEvent &);
        PyObject *py_event = Borrow__ThreadEvent(e);
        DoCall(py_event);
    }

    void operator()(wxContextMenuEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__ContextMenuEvent(const wxContextMenuEvent &);
        PyObject *py_event = Borrow__ContextMenuEvent(e);
        DoCall(py_event);
    }

    void operator()(wxCloseEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__CloseEvent(const wxCloseEvent &);
        PyObject *py_event = Borrow__CloseEvent(e);
        DoCall(py_event);
    }

    void operator()(wxInitDialogEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__InitDialogEvent(const wxInitDialogEvent &);
        PyObject *py_event = Borrow__InitDialogEvent(e);
        DoCall(py_event);
    }

    void operator()(wxMoveEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__MoveEvent(const wxMoveEvent &);
        PyObject *py_event = Borrow__MoveEvent(e);
        DoCall(py_event);
    }

    void operator()(wxIconizeEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__IconizeEvent(const wxIconizeEvent &);
        PyObject *py_event = Borrow__IconizeEvent(e);
        DoCall(py_event);
    }

    void operator()(wxDisplayChangedEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__DisplayChangedEvent(const wxDisplayChangedEvent &);
        PyObject *py_event = Borrow__DisplayChangedEvent(e);
        DoCall(py_event);
    }

    void operator()(wxShowEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__ShowEvent(const wxShowEvent &);
        PyObject *py_event = Borrow__ShowEvent(e);
        DoCall(py_event);
    }

    void operator()(wxMaximizeEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__MaximizeEvent(const wxMaximizeEvent &);
        PyObject *py_event = Borrow__MaximizeEvent(e);
        DoCall(py_event);
    }

    void operator()(wxMenuEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__MenuEvent(const wxMenuEvent &);
        PyObject *py_event = Borrow__MenuEvent(e);
        DoCall(py_event);
    }

    void operator()(wxNcPaintEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__NcPaintEvent(const wxNcPaintEvent &);
        PyObject *py_event = Borrow__NcPaintEvent(e);
        DoCall(py_event);
    }

    void operator()(wxChildFocusEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__ChildFocusEvent(const wxChildFocusEvent &);
        PyObject *py_event = Borrow__ChildFocusEvent(e);
        DoCall(py_event);
    }

    void operator()(wxProcessEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__ProcessEvent(const wxProcessEvent &);
        PyObject *py_event = Borrow__ProcessEvent(e);
        DoCall(py_event);
    }

    void operator()(wxWindowDestroyEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__WindowDestroyEvent(const wxWindowDestroyEvent &);
        PyObject *py_event = Borrow__WindowDestroyEvent(e);
        DoCall(py_event);
    }

    void operator()(wxActivateEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__ActivateEvent(const wxActivateEvent &);
        PyObject *py_event = Borrow__ActivateEvent(e);
        DoCall(py_event);
    }

    void operator()(wxMouseCaptureChangedEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__MouseCaptureChangedEvent(const wxMouseCaptureChangedEvent &);
        PyObject *py_event = Borrow__MouseCaptureChangedEvent(e);
        DoCall(py_event);
    }

    void operator()(wxHelpEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__HelpEvent(const wxHelpEvent &);
        PyObject *py_event = Borrow__HelpEvent(e);
        DoCall(py_event);
    }

    void operator()(wxClipboardTextEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__ClipboardTextEvent(const wxClipboardTextEvent &);
        PyObject *py_event = Borrow__ClipboardTextEvent(e);
        DoCall(py_event);
    }

    void operator()(wxSetCursorEvent &e) {
        PBPP_NEW_THREAD_BLOCKER
        PyObject *Borrow__SetCursorEvent(const wxSetCursorEvent &);
        PyObject *py_event = Borrow__SetCursorEvent(e);
        DoCall(py_event);
    }
};

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

        PYEVENT(wxEVT_BUTTON)
        PYEVENT(wxEVT_CHECKBOX)
        PYEVENT(wxEVT_CHOICE)
        PYEVENT(wxEVT_LISTBOX)
        PYEVENT(wxEVT_LISTBOX_DCLICK)
        PYEVENT(wxEVT_CHECKLISTBOX)
        PYEVENT(wxEVT_MENU)
        PYEVENT(wxEVT_SLIDER)
        PYEVENT(wxEVT_RADIOBOX)
        PYEVENT(wxEVT_RADIOBUTTON)
        PYEVENT(wxEVT_SCROLLBAR)
        PYEVENT(wxEVT_VLBOX)
        PYEVENT(wxEVT_COMBOBOX)
        PYEVENT(wxEVT_TOOL_RCLICKED)
        PYEVENT(wxEVT_TOOL_DROPDOWN)
        PYEVENT(wxEVT_TOOL_ENTER)
        PYEVENT(wxEVT_COMBOBOX_DROPDOWN)
        PYEVENT(wxEVT_COMBOBOX_CLOSEUP)
        PYEVENT(wxEVT_THREAD)
        PYEVENT(wxEVT_ASYNC_METHOD_CALL)
        PYEVENT(wxEVT_LEFT_DOWN)
        PYEVENT(wxEVT_LEFT_UP)
        PYEVENT(wxEVT_MIDDLE_DOWN)
        PYEVENT(wxEVT_MIDDLE_UP)
        PYEVENT(wxEVT_RIGHT_DOWN)
        PYEVENT(wxEVT_RIGHT_UP)
        PYEVENT(wxEVT_MOTION)
        PYEVENT(wxEVT_ENTER_WINDOW)
        PYEVENT(wxEVT_LEAVE_WINDOW)
        PYEVENT(wxEVT_LEFT_DCLICK)
        PYEVENT(wxEVT_MIDDLE_DCLICK)
        PYEVENT(wxEVT_RIGHT_DCLICK)
        PYEVENT(wxEVT_SET_FOCUS)
        PYEVENT(wxEVT_KILL_FOCUS)
        PYEVENT(wxEVT_CHILD_FOCUS)
        PYEVENT(wxEVT_MOUSEWHEEL)
        PYEVENT(wxEVT_AUX1_DOWN)
        PYEVENT(wxEVT_AUX1_UP)
        PYEVENT(wxEVT_AUX1_DCLICK)
        PYEVENT(wxEVT_AUX2_DOWN)
        PYEVENT(wxEVT_AUX2_UP)
        PYEVENT(wxEVT_AUX2_DCLICK)
        PYEVENT(wxEVT_CHAR)
        PYEVENT(wxEVT_CHAR_HOOK)
        PYEVENT(wxEVT_NAVIGATION_KEY)
        PYEVENT(wxEVT_KEY_DOWN)
        PYEVENT(wxEVT_KEY_UP)
        PYEVENT(wxEVT_HOTKEY)
        PYEVENT(wxEVT_AFTER_CHAR)
        PYEVENT(wxEVT_SET_CURSOR)
        PYEVENT(wxEVT_SCROLL_TOP)
        PYEVENT(wxEVT_SCROLL_BOTTOM)
        PYEVENT(wxEVT_SCROLL_LINEUP)
        PYEVENT(wxEVT_SCROLL_LINEDOWN)
        PYEVENT(wxEVT_SCROLL_PAGEUP)
        PYEVENT(wxEVT_SCROLL_PAGEDOWN)
        PYEVENT(wxEVT_SCROLL_THUMBTRACK)
        PYEVENT(wxEVT_SCROLL_THUMBRELEASE)
        PYEVENT(wxEVT_SCROLL_CHANGED)
        PYEVENT(wxEVT_SCROLLWIN_TOP)
        PYEVENT(wxEVT_SCROLLWIN_BOTTOM)
        PYEVENT(wxEVT_SCROLLWIN_LINEUP)
        PYEVENT(wxEVT_SCROLLWIN_LINEDOWN)
        PYEVENT(wxEVT_SCROLLWIN_PAGEUP)
        PYEVENT(wxEVT_SCROLLWIN_PAGEDOWN)
        PYEVENT(wxEVT_SCROLLWIN_THUMBTRACK)
        PYEVENT(wxEVT_SCROLLWIN_THUMBRELEASE)
        PYEVENT(wxEVT_SIZE)
        PYEVENT(wxEVT_MOVE)
        PYEVENT(wxEVT_CLOSE_WINDOW)
        PYEVENT(wxEVT_END_SESSION)
        PYEVENT(wxEVT_QUERY_END_SESSION)
        PYEVENT(wxEVT_ACTIVATE_APP)
        PYEVENT(wxEVT_ACTIVATE)
        PYEVENT(wxEVT_CREATE)
        PYEVENT(wxEVT_DESTROY)
        PYEVENT(wxEVT_SHOW)
        PYEVENT(wxEVT_ICONIZE)
        PYEVENT(wxEVT_MAXIMIZE)
        PYEVENT(wxEVT_MOUSE_CAPTURE_CHANGED)
        PYEVENT(wxEVT_MOUSE_CAPTURE_LOST)
        PYEVENT(wxEVT_PAINT)
        PYEVENT(wxEVT_ERASE_BACKGROUND)
        PYEVENT(wxEVT_NC_PAINT)
        PYEVENT(wxEVT_MENU_OPEN)
        PYEVENT(wxEVT_MENU_CLOSE)
        PYEVENT(wxEVT_MENU_HIGHLIGHT)
        PYEVENT(wxEVT_CONTEXT_MENU)
        PYEVENT(wxEVT_SYS_COLOUR_CHANGED)
        PYEVENT(wxEVT_DISPLAY_CHANGED)
        PYEVENT(wxEVT_QUERY_NEW_PALETTE)
        PYEVENT(wxEVT_PALETTE_CHANGED)
        PYEVENT(wxEVT_JOY_BUTTON_DOWN)
        PYEVENT(wxEVT_JOY_BUTTON_UP)
        PYEVENT(wxEVT_JOY_MOVE)
        PYEVENT(wxEVT_JOY_ZMOVE)
        PYEVENT(wxEVT_DROP_FILES)
        PYEVENT(wxEVT_INIT_DIALOG)
        PYEVENT(wxEVT_IDLE)
        PYEVENT(wxEVT_UPDATE_UI)
        PYEVENT(wxEVT_SIZING)
        PYEVENT(wxEVT_MOVING)
        PYEVENT(wxEVT_MOVE_START)
        PYEVENT(wxEVT_MOVE_END)
        PYEVENT(wxEVT_HIBERNATE)
        PYEVENT(wxEVT_TEXT_COPY)
        PYEVENT(wxEVT_TEXT_CUT)
        PYEVENT(wxEVT_TEXT_PASTE)
        PYEVENT(wxEVT_TEXT)
        PYEVENT(wxEVT_TEXT_ENTER)
        PYEVENT(wxEVT_TEXT_URL)
        PYEVENT(wxEVT_TEXT_MAXLEN)
        PYEVENT(wxEVT_COMMAND_LEFT_CLICK)
        PYEVENT(wxEVT_COMMAND_LEFT_DCLICK)
        PYEVENT(wxEVT_COMMAND_RIGHT_CLICK)
        PYEVENT(wxEVT_COMMAND_RIGHT_DCLICK)
        PYEVENT(wxEVT_COMMAND_SET_FOCUS)
        PYEVENT(wxEVT_COMMAND_KILL_FOCUS)
        PYEVENT(wxEVT_COMMAND_ENTER)
        PYEVENT(wxEVT_HELP)
        PYEVENT(wxEVT_DETAILED_HELP)
        PYEVENT(wxEVT_LIST_BEGIN_DRAG)
        PYEVENT(wxEVT_LIST_BEGIN_RDRAG)
        PYEVENT(wxEVT_LIST_BEGIN_LABEL_EDIT)
        PYEVENT(wxEVT_LIST_END_LABEL_EDIT)
        PYEVENT(wxEVT_LIST_DELETE_ITEM)
        PYEVENT(wxEVT_LIST_DELETE_ALL_ITEMS)
        PYEVENT(wxEVT_LIST_ITEM_SELECTED)
        PYEVENT(wxEVT_LIST_ITEM_DESELECTED)
        PYEVENT(wxEVT_LIST_KEY_DOWN)
        PYEVENT(wxEVT_LIST_INSERT_ITEM)
        PYEVENT(wxEVT_LIST_COL_CLICK)
        PYEVENT(wxEVT_LIST_ITEM_RIGHT_CLICK)
        PYEVENT(wxEVT_LIST_ITEM_MIDDLE_CLICK)
        PYEVENT(wxEVT_LIST_ITEM_ACTIVATED)
        PYEVENT(wxEVT_LIST_CACHE_HINT)
        PYEVENT(wxEVT_LIST_COL_RIGHT_CLICK)
        PYEVENT(wxEVT_LIST_COL_BEGIN_DRAG)
        PYEVENT(wxEVT_LIST_COL_DRAGGING)
        PYEVENT(wxEVT_LIST_COL_END_DRAG)
        PYEVENT(wxEVT_LIST_ITEM_FOCUSED)
        PYEVENT(wxEVT_TREE_BEGIN_DRAG)
        PYEVENT(wxEVT_TREE_BEGIN_RDRAG)
        PYEVENT(wxEVT_TREE_BEGIN_LABEL_EDIT)
        PYEVENT(wxEVT_TREE_END_LABEL_EDIT)
        PYEVENT(wxEVT_TREE_DELETE_ITEM)
        PYEVENT(wxEVT_TREE_GET_INFO)
        PYEVENT(wxEVT_TREE_SET_INFO)
        PYEVENT(wxEVT_TREE_ITEM_EXPANDED)
        PYEVENT(wxEVT_TREE_ITEM_EXPANDING)
        PYEVENT(wxEVT_TREE_ITEM_COLLAPSED)
        PYEVENT(wxEVT_TREE_ITEM_COLLAPSING)
        PYEVENT(wxEVT_TREE_SEL_CHANGED)
        PYEVENT(wxEVT_TREE_SEL_CHANGING)
        PYEVENT(wxEVT_TREE_KEY_DOWN)
        PYEVENT(wxEVT_TREE_ITEM_ACTIVATED)
        PYEVENT(wxEVT_TREE_ITEM_RIGHT_CLICK)
        PYEVENT(wxEVT_TREE_ITEM_MIDDLE_CLICK)
        PYEVENT(wxEVT_TREE_END_DRAG)
        PYEVENT(wxEVT_TREE_STATE_IMAGE_CLICK)
        PYEVENT(wxEVT_TREE_ITEM_GETTOOLTIP)
        PYEVENT(wxEVT_TREE_ITEM_MENU)
        PYEVENT(wxEVT_END_PROCESS)
        PYEVENT(wxEVT_TIMER)

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
        }
        else {
            p->Bind(tag, s_functor, id, lastId, userData);
        }
    }
    else {
        wxEventTypeTag<wxPyEvent> tag(event.GetEventType());
        if (unbind) {
            ret = p->Unbind(tag, s_functor, id, lastId, userData);
        }
        else {
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
}
