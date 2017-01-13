/***************************************************************
 * Name:      XRC.hxx
 * Purpose:   XRC 的强制类型转换
 * Author:    Wang Xiaoning (vanxining@139.com)
 * Created:   2016-12-25
 **************************************************************/
#pragma once

class wxWindow;

#define CONTROL_LIST \
    XRC_CONV(wxFrame) \
    XRC_CONV(wxDialog) \
    XRC_CONV(wxMenuBar) \
    XRC_CONV(wxStatusBar) \
    XRC_CONV(wxButton) \
    XRC_CONV(wxTextCtrl) \
    XRC_CONV(wxListBox) \
    XRC_CONV(wxCheckListBox) \
    XRC_CONV(wxListCtrl) \
    XRC_CONV(wxListView) \
    XRC_CONV(wxNotebook) \

#define XRC_CONV(T) class T;
CONTROL_LIST
#undef XRC_CONV

#define XRC_CONV(T) T *To_ ## T(wxWindow *window);
namespace XRC {
    CONTROL_LIST

    int GetDefaultEventType(const char *cls);
}
#undef XRC_CONV
