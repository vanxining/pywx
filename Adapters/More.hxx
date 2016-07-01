/***************************************************************
 * Name:      More.hxx
 * Purpose:   对 wxWidgets 某些不合理接口的一些补充
 * Author:    Wang Xiaoning (vanxining@139.com)
 * Created:   2014-12-03
 **************************************************************/
#pragma once

#ifndef __GCCXML__
#   include "../Gen/_Python.hxx"
#else
    struct PyObject;
    class wxOutputStream;
    class wxInputStream;
#endif

// bool wxOutputStream::WriteAll(const void *buffer, unsigned int size)
// @param bytes Python 2.x 下为 str 类型，3.x 下为 bytes 类型
PyObject *OutputStream_Write(wxOutputStream *outs, PyObject *bytes);

// 读取整个流，直到遇到一个错误（如 EOF）
// @return 一个二进制数组：Python 2.x 下为 str 类型，3.x 下为 bytes 类型
PyObject *InputStream_Read(wxInputStream *ins);

/// HiDPI 支持
void wxSetProcessDPIAware();

//////////////////////////////////////////////////////////////////////////
/// TODO: 这些都应该作为一个 PyBridge++ 的基础设施

/// 将一个 char * 转换为 Python Unicode 字符串
PyObject *CharArrayToPyString(PyObject *py_text);
