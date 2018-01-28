/***************************************************************
* Name:      PyApp.hxx
* Purpose:   wxApp 包裹器
* Author:    Wang Xiaoning (vanxining@139.com)
* Created:   2014-01
**************************************************************/
#pragma once
#include <wx/app.h>

//----------------------------------------------------------------------
// Classes for implementing the pywx main application shell.
//----------------------------------------------------------------------
class wxPyApp : public wxApp {
public:
    wxPyApp();
    ~wxPyApp();

    /// 调用 Python 端的 OnInit()
    /// C++ 无法实现在构造函数中调用虚函数，但 Python 是可以的
    void _BootstrapApp();
    virtual int MainLoop();

    static bool IsDisplayAvailable();

    /// @note implementation only
    void SetStartupComplete(bool val);

private:

    // 初始化是否已然完成
    bool m_startup_completed;

#if PY_MAJOR_VERSION >= 3
    typedef wchar_t arg_char_type;
#else
    typedef char arg_char_type;
#endif
    arg_char_type **m_argv;

private:

    DECLARE_ABSTRACT_CLASS(wxPyApp)
};

wxPyApp *wxGetApp();
