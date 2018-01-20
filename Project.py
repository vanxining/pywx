import os
import sys
import StringIO

import ProjectBase
import Converters
import Module
import Types
import Util


_sep = os.path.sep

output_cxx_dir = os.path.dirname(__file__) + _sep + "Gen"
output_cxx_ext = ".cxx"

header_wrappers_dir = "{0}{1}Hacks{1}".format(os.path.dirname(__file__), _sep)
header_wrappers_ext = ".pbpp.hxx"

castxml_bin = r'castxml'
_castxml_args = r'--castxml-output=1 -w -x c++ -std=c++14 -D__CASTXML__ -fms-compatibility-version=19 -I"D:\Work\CppLibs\wxMSW\include" -I"D:\Work\CppLibs\wxMSW\lib\vc_lib\mswu" -DWXDLLIMPEXP_CORE'


def castxml_args(header_path):
    return _castxml_args


_subheaders = {
    "listctrl.h": ["listbase.h", "itemattr.h",],
    "dataobj.h": ["dataform.h", "dataobj2.h",],
}


def select_headers(header_path, xml_path):
    # Restore the temporary wrapper header to the original entry header
    # The first <File> tag is always the entry header generating the XML file
    with open(xml_path, "r+") as f:
        content = f.read()
        pos = content.index("<File ")

        temp_path = ProjectBase.get_temp_cpp_header_path(header_path)
        if temp_path != header_path:
            content = content[:pos] + content[pos:].replace(temp_path, header_path)

            f.seek(0)
            f.write(content)

    short_name = os.path.split(header_path)[1]
    subheaders = _subheaders[short_name] if short_name in _subheaders else []
    subheaders.append(short_name)

    headers = []

    # Select other platform-specific headers with the same base name
    # (along with the entry header)
    beg = pos
    while True:
        beg = content.find('name="', beg)
        if beg == -1:
            break

        beg += 6
        end = content.index('"', beg)
        full_path = content[beg:end]
        beg = end

        for header in subheaders:
            pos = full_path.find(header)
            if pos != -1 and not full_path[pos - 1].isalnum():
                headers.append(full_path)

    assert len(headers) > 0
    return headers


class Project(ProjectBase.ProjectBase):
    def __init__(self):
        ProjectBase.ProjectBase.__init__(self, None)

        __wx__ = Util.load("wxMSW")

        self.add_converters(__wx__)

        class _Interfaces:
            def __init__(self):
                self.self_setter = "SetSelf(%s)"
                self.self_getter = "GetSelf()"

        interfaces = _Interfaces()
        Types.PythonAwareClassRegistry.add("wxPyEvent", interfaces)
        Types.PythonAwareClassRegistry.add("wxPyCommandEvent", interfaces)

        self.root_mod = Module.Module(
            "wx", None,
            __wx__.WxPythonNamer(),
            __wx__.WxHeaderProvider(),
            __wx__.WxFlagsAssigner(),
            __wx__.WxBlacklist()
        )

        pdl = __wx__.ProcessingDoneListener()
        self.root_mod.processing_done_listener = pdl

    def add_converters(self, __wx__):
        Converters.clear()

        Converters.add(__wx__.WxStringConv())
        Converters.add(Converters.StrConv())
        Converters.add(Converters.WcsConv())

        def convert_list(wx_type_name, item_type_decl_list):
            item_type = Types.Type(item_type_decl_list, 999, "Class")
            Converters.add(__wx__.WxListConv(item_type, wx_type_name))

        convert_list("wxList", ("wxObject", "*",))
        convert_list("wxPointList", ("wxPoint", "*",))
        convert_list("wxGDIImageHandlerList", ("wxGDIImageHandler", "*",))
        convert_list("wxWindowList", ("wxWindow", "*",))
        convert_list("wxSizerItemList", ("wxSizerItem", "*",))
        convert_list("wxMenuItemList", ("wxMenuItem", "*",))
        convert_list("wxArrayInt", ("int",))
        convert_list("wxArrayLong", ("long int",))
        convert_list("wxArrayDouble", ("double",))
        convert_list("wxArrayString", ("wxString",))

        K = Types.Type(("wxString",), 0, "Class")
        V = Types.Type(("wxString",), 0, "Class")
        Converters.add(__wx__.WxDictConv(K, V, "wxStringToStringHashMap"))

    def try_update(self):
        __wx__, reloaded = Util.load2("wxMSW")

        if reloaded:
            self.add_converters(__wx__)

            self.root_mod.update_strategies(
                __wx__.WxPythonNamer(),
                __wx__.WxHeaderProvider(),
                __wx__.WxFlagsAssigner(),
                __wx__.WxBlacklist()
            )

            pdl = __wx__.ProcessingDoneListener()
            self.root_mod.processing_done_listener = pdl
