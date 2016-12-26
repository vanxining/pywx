/***************************************************************
 * Name:      More.hxx
 * Purpose:   �� wxWidgets ĳЩ������ӿڵ�һЩ����
 * Author:    Wang Xiaoning (vanxining@139.com)
 * Created:   2014-12-03
 **************************************************************/
#pragma once

#ifndef __CASTXML__
#   include "../Gen/_Python.hxx"
#else
    struct PyObject;
    class wxOutputStream;
    class wxInputStream;
    class wxDropFilesEvent;
#endif

// bool wxOutputStream::WriteAll(const void *buffer, unsigned int size)
// @param bytes Python 2.x ��Ϊ str ���ͣ�3.x ��Ϊ bytes ����
PyObject *OutputStream_Write(wxOutputStream *outs, PyObject *bytes);

// ��ȡ��������ֱ������һ�������� EOF��
// @return һ�����������飺Python 2.x ��Ϊ str ���ͣ�3.x ��Ϊ bytes ����
PyObject *InputStream_Read(wxInputStream *ins);

// ������Ҫ����һ�� wxString ������
PyObject *DropFilesEvent_GetFiles(wxDropFilesEvent *event);

/// HiDPI ֧��
void wxSetProcessDPIAware();

//////////////////////////////////////////////////////////////////////////
/// TODO: ��Щ��Ӧ����Ϊһ�� PyBridge++ �Ļ�����ʩ

/// ��һ�� char * ת��Ϊ Python Unicode �ַ���
PyObject *CharArrayToPyString(PyObject *py_text);
