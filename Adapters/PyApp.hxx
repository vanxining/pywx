/***************************************************************
* Name:      PyApp.hxx
* Purpose:   wxApp ������
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

    /// ���� Python �˵� OnInit()
    /// C++ �޷�ʵ���ڹ��캯���е����麯������ Python �ǿ��Ե�
    void _BootstrapApp();
    virtual int MainLoop();

    static bool IsDisplayAvailable();

    /// @note implementation only
    void SetStartupComplete(bool val);

private:

    // ��ʼ���Ƿ���Ȼ���
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
