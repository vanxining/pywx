-- ----------------------------------------------------------------------------
--    Name:        wxpresents4.lua, a Premake4 script
--    Author:      Ben Cleveland, based on wxpresents.lua by Ryan Pusztai
--    Date:        11/24/2010
--    Version:     1.00
-- ----------------------------------------------------------------------------

function ActionUsesGCC()
    if _ACTION then
        match = string.find("gmake codelite codeblocks xcode3", _ACTION)
        return match ~= nil
    end

    return false
end

function ActionUsesMSVC()
    return _ACTION and _ACTION:find("vs")
end

function GetCustomValue(item)
    local prj = project()
    for _, block in pairs(prj.blocks) do
        if block[item] then
            return block[item]
        end
    end
    return nil
end

-- Package options
newoption {
    trigger = "wx-shared",
    description = "Link against wxWidgets as a shared library"
}

newoption {
    trigger     = "unicode",
    description = "Use the Unicode character set."
}

-- Namespace
wx = {}


if "windows" == os.get() then
    wx.root = os.getenv("WXWIN")
    if not wx.root then
        error("missing the WXWIN environment variable")
    end

    -- Ensure that headers exist.
    local f = io.open(wx.root .. "/include/wx/wx.h")
    if f == nil then
        error("can't find include/wx/wx.h! - check the value of WXWIN (" .. wx.root .. ")")
    end

end

--- Configure a C/C++ package to use wxWidgets
--- wx.Configure(shouldSetTarget = true, wxVer = "30")
function wx.Configure(shouldSetTarget, wxVer)
    -- Set the default values.
    if shouldSetTarget == nil then shouldSetTarget = true end
    local targetName = project().name
    local wx_ver = wxVer or "30"

    ----------------------------------------------------------

    flags "Unicode"

    -- Set the defines.
    defines "wxUSE_UNICODE"
    defines "__WX__"

    ----------------------------------------------------------

    configuration "Debug"
        defines "__WXDEBUG__"
        flags "Symbols"

    configuration "Release"
        flags "Optimize"

    configuration({})

    if _OPTIONS["wx-shared"] then
        defines "WXUSINGDLL"
    end

    ----------------------------------------------------------

    local kindVal = GetCustomValue("kind") or ""

    if "windows" == os.get() then
        -- ******* WINDOWS SETUP ***********
        -- *    Settings that are Windows specific.
        -- *********************************

        -- Set wxWidgets include paths
        if _ACTION == "cb-gcc" then
            -- Needed for the resource complier.
            includedirs { "$(#WX.include)" }
            buildoptions { "-isystem $(#WX.include)" }
        elseif _ACTION == "cl-gcc" then
            -- Needed for the resource complier.
            includedirs { wx.root .. "/include" }
            buildoptions { "-isystem " .. wx.root .. "/include" }
        elseif _ACTION == "gmake" then
            -- Needed for the resource complier.
            includedirs { wx.root .. "/include" }
            buildoptions { "-isystem \"" .. wx.root .. "/include\"" }
        else
            includedirs { wx.root .. "/include" }
        end

        -- Set the correct "setup.h" include path
        if _ACTION == "codeblocks" then
            if _OPTIONS["wx-shared"] then
                configuration "Debug"
                    includedirs { "$(#WX.lib)/gcc_dll/mswud" }
                configuration "Release"
                    includedirs { "$(#WX.lib)/gcc_dll/mswu" }
            else
                configuration "Debug"
                    includedirs { "$(#WX.lib)/gcc_lib/mswud" }
                configuration "Release"
                    includedirs { "$(#WX.lib)/gcc_lib/mswu" }
            end
        elseif ActionUsesGCC() then
            if _OPTIONS["wx-shared"] then
                configuration "Debug"
                    includedirs { wx.root .. "/lib/gcc_dll/mswud" }
                configuration "Release"
                    includedirs { wx.root .. "/lib/gcc_dll/mswu" }
            else
                configuration "Debug"
                    includedirs { wx.root .. "/lib/gcc_lib/mswud" }
                configuration "Release"
                    includedirs { wx.root .. "/lib/gcc_lib/mswu" }
            end
        else
            if _OPTIONS["wx-shared"] then
                configuration "Debug"
                    includedirs { wx.root .. "/lib/vc_dll/mswud" }
                configuration "Release"
                    includedirs { wx.root .. "/lib/vc_dll/mswu" }
            else
                configuration "Debug"
                    includedirs { wx.root .. "/lib/vc_lib/mswud" }
                configuration "Release"
                    includedirs { wx.root .. "/lib/vc_lib/mswu" }
            end
        end

        configuration({})

        -- Set the linker options.

        if _ACTION == "codeblocks" then
            if _OPTIONS["wx-shared"] then
                libdirs { "$(#WX.lib)/gcc_dll" }
            else
                libdirs { "$(#WX.lib)/gcc_lib" }
            end
        elseif ActionUsesGCC() then
            if _OPTIONS["wx-shared"] then
                libdirs { wx.root .. "/lib/gcc_dll" }
            else
                libdirs { wx.root .. "/lib/gcc_lib" }
            end
        else
            if _OPTIONS["wx-shared"] then
                libdirs { wx.root .. "/lib/vc_dll" }
            else
                libdirs { wx.root .. "/lib/vc_lib" }
            end
        end
        local winLibs = {
            "wsock32", "comctl32", "psapi", "ws2_32",
            "ole32", "winmm", "oleaut32", "odbc32", "advapi32",
            "oleaut32", "uuid", "rpcrt4", "gdi32", "comdlg32",
            "winspool", "shell32", "kernel32"
        }
        if ActionUsesMSVC() then
            table.insert(winLibs, { "gdiplus" })
        end

        -- Set wxWidgets libraries to link. The order we insert matters for the linker.

        local wxLibs = {
            "core", "adv", "html", "xrc"
        }
        local wxLibs2 = {
            "wxexpat", "wxjpeg", "wxpng", "wxregexu", "wxtiff", "wxzlib"
        }

        configuration { "Debug", "not StaticLib" }
            links { "wxbase" ..  wx_ver .. "ud" }
            links { "wxbase" ..  wx_ver .. "ud_xml" }
            for _, lib in ipairs(wxLibs) do
                links { "wxmsw" .. wx_ver .. "ud_" .. lib }
            end
            for _, lib in ipairs(wxLibs2) do
                links { lib .. "d" }
            end
            for _, lib in ipairs(winLibs) do
                links { lib }
            end

        configuration { "Release", "not StaticLib" }
            links { "wxbase" ..  wx_ver .. "u" }
            links { "wxbase" ..  wx_ver .. "u_xml" }
            for _, lib in ipairs(wxLibs) do
                links { "wxmsw" .. wx_ver .. "u_" .. lib }
            end
            for _, lib in ipairs(wxLibs2) do
                links { lib }
            end
            for _, lib in ipairs(winLibs) do
                links { lib }
            end

        configuration({})

        if kindVal == "WindowedApp" then
            flags { "WinMain" }
        end

        -- Set the Windows defines.
        defines { "__WXMSW__" }
        -- Set the targets.
        if shouldSetTarget then
            if not (kindVal == "WindowedApp" or kindVal == "ConsoleApp") then
                if ActionUsesGCC() then
                    configuration { "Debug" }
                        targetdir { "wxmsw" .. wx_ver .. "umd_" .. targetName .. "_gcc" }
                    configuration { "Release" }
                        targetdir { "wxmsw" .. wx_ver .. "um_" .. targetName .. "_gcc" }
                else
                    configuration { "Debug" }
                        targetdir { "wxmsw" .. wx_ver .. "umd_" .. targetName .. "_vc" }
                    configuration { "Release" }
                        targetdir { "wxmsw" .. wx_ver .. "um_" .. targetName .. "_vc" }
                end
            end
        end

        configuration({})

    else
    -- ******* LINUX SETUP *************
    -- *    Settings that are Linux specific.
    -- *********************************
        -- Ignore resource files in Linux.
        excludes "**.rc"

        -- Set wxWidgets Debug build/link options.
        configuration { "Debug" }
            buildoptions { "`wx-config --debug=yes --cflags`" }
            linkoptions { "`wx-config --debug=yes --libs std`" }

        -- Set the wxWidgets Release build/link options.
        configuration { "Release" }
            buildoptions { "`wx-config --debug=no --cflags`" }
            linkoptions { "`wx-config --libs std`" }

        -- Set the Linux defines.
        configuration({})
        defines "__WXGTK__"

        -- Set the targets.
        if shouldSetTarget then
            if not (kindVal == "WindowedApp" or kindVal == "ConsoleApp") then
                configuration { "Debug" }
                    targetdir { wx.LibName(targetName, wxVer, true) }
                configuration { "Release" }
                    targetdir { wx.LibName(targetName, wxVer) }
            end
        end
    end

    configuration({})
end

function wx.PosixLibName(targetName, isDebug)
    local dbg = isDebug or false
    local debug = "no"
    if dbg then debug = "yes" end

    return
end

function wx.LibName(targetName, wxVer, isDebug)
    local name = ""
    -- Make the parameters optional.
    local wx_ver = wxVer or "30"
    local debug = ""
    local unicode = ""
    if isDebug then debug = "d" end
    if _OPTIONS["unicode"] then unicode = "u" end

    if "windows" == os.get() then
        local monolithic = ""
        local vc8 = ""

        if _OPTIONS["wx-shared"] then monolithic = "m" end
        name = "wxmsw" .. wx_ver .. unicode .. monolithic .. debug .. "_" .. targetName
    elseif "linux" == os.get() then
        wx_ver = wx_ver:sub(1, 1) .. "." .. wx_ver:sub(2)
        name = "wx_gtk2" .. unicode .. debug .. "_" .. targetName:lower() .. "-" .. wx_ver
    else
        local debug = "no"
        if isDebug then debug = "yes" end
        name = "`wx-config --debug=" .. debug .. " --basename`_" .. targetName .. "-`wx-config --release`"
    end

    return name
end
