require "wxpresets4"

newoption {
    trigger = "pydebug",
    description = "Link with Python debug build"
}

solution "pywx"
    configurations { "Debug", "Release" }

    project "pywx"
        kind "SharedLib"
        defines "_USRDLL"

        language "C++"

        tn = "wx"
        targetextension ".pyd"
        implibextension ".lib"

        if _OPTIONS["pydebug"] then
            targetname(tn .. "_d")
        else
            targetname(tn)
        end

        includedirs { ".." }

        headers = { "../**.hxx", "../**.hpp" }
        sources = { "../**.cxx", "../**.cpp" }

        files { headers, sources }
        excludes { "../Hacks/**" }
        vpaths {
           ["Header Files/*"] = headers,
           ["Source Files/*"] = sources,
        }

        py_ver = 27

        if _OPTIONS["pydebug"] and py_ver < 30 then
            python_root = os.getenv("SystemDrive") .. "/Build" .. py_ver .. "/CPython"

            includedirs { python_root .. "/PC" }
            libdirs { python_root .. "/PCbuild" }
        else
            python_root = os.getenv("SystemDrive") .. "/Python" .. py_ver

            libdirs { python_root .. "/libs" }
        end

        includedirs { python_root .. "/include" }

        defines { "WIN32", "_WINDOWS", "ISOLATION_AWARE_ENABLED=1" }
        defines { "PBPP_SUPPORT_THREAD" }

        includedirs { "../Gen/Precomp" } -- for StdAfx.hpp
        pchheader "StdAfx.hpp"
        pchsource "../Gen/Precomp/StdAfx.cpp"

        wx.Configure(false, "31")

        if _ACTION == "gmake" then
            buildoptions { "-finput-charset=GBK" }
        end

        configuration { "Debug" }
            defines { "_DEBUG", "DEBUG" }

            if _OPTIONS["pydebug"] then
                defines "PYTHON_DEBUG_BUILD"
                links { "python" .. py_ver .. "_d" }
            else
                links { "python" .. py_ver }
            end

        configuration { "Release" }
            defines { "NDEBUG" }
            links { "python" .. py_ver }