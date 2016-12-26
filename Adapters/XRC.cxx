/***************************************************************
 * Name:      XRC.cxx
 * Purpose:   XRC 的强制类型转换
 * Author:    Wang Xiaoning (vanxining@139.com)
 * Created:   2016-12-25
 **************************************************************/
#include "StdAfx.hpp"

#include "XRC.hxx"

#include <string>
#include <unordered_map>

//////////////////////////////////////////////////////////////////////////

#define XRC_CONV(T) \
T *To_ ## T(wxWindow *window) { \
   return reinterpret_cast<T *>(window); \
}
namespace XRC {
    CONTROL_LIST

    int GetDefaultEventType(const char *cls) {
        static std::unordered_map<std::string, int> s_mappings = {
            { "wxButton", wxEVT_BUTTON },
            { "wxMenuItem", wxEVT_MENU },
        };

        auto &&it = s_mappings.find(cls);
        if (it != s_mappings.end()) {
            return it->second;
        }

        return 0;
    }
}
#undef XRC_CONV
