import os
import sys
import StringIO
import re


if "PBPP" in os.environ and os.environ["PBPP"] not in sys.path:
    sys.path = [os.environ["PBPP"],] + sys.path


import ProjectBase
import Converters
import Module

from Util import load, load2
import Types

_sep = os.path.sep

output_cxx_dir = os.path.dirname(__file__) + _sep + "Gen"
output_cxx_ext = ".cxx"

header_wrappers_dir = os.path.dirname(__file__) + _sep + "Hacks" + _sep
header_wrappers_ext = ".pbpp.hxx"

gccxml_bin = r'D:\CppSource\Temp\CastXML\vcbuild\bin\RelWithDebInfo\castxml.exe'
_gccxml_args = r'--castxml-gccxml -w -x c++ -std=c++14 -fms-compatibility-version=19 -I"D:\Work\CppLibs\wxMSW\include" -I"D:\Work\CppLibs\wxMSW\lib\vc_lib\mswu" -D__GCCXML__ -DWXDLLIMPEXP_CORE'


def gccxml_args(header_path):
    return _gccxml_args


def select_headers(header_path, xml_path):
    short_name = os.path.split(header_path)[1]
    pattern = re.compile(r"\W" + short_name.replace('.', r"\."))

    with open(xml_path, "r+") as f:
        content = f.read()
        pos = content.index("<File ")

        temp_path = ProjectBase.get_temp_cpp_header_path(header_path)
        if temp_path != header_path:
            content = content[:pos] + content[pos:].replace(temp_path, header_path)

            f.seek(0)
            f.write(content)

    headers = []

    beg = pos
    while True:
        beg = content.find('name="', beg)
        if beg == -1:
            break

        beg += 6
        end = content.index('"', beg)
        path = content[beg:end]

        if pattern.search(path):
            headers.append(path)

        beg = end

    assert len(headers) > 0
    return headers


class Project(ProjectBase.ProjectBase):
    def __init__(self):
        ProjectBase.ProjectBase.__init__(self, None)

        __wx__ = load("wxMSW")

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

    def try_update(self):
        __wx__, reloaded = load2("wxMSW")

        if reloaded:
            self.root_mod.update_strategies(
                __wx__.WxPythonNamer(),
                __wx__.WxHeaderProvider(),
                __wx__.WxFlagsAssigner(),
                __wx__.WxBlacklist()
            )

            pdl = __wx__.ProcessingDoneListener()
            self.root_mod.processing_done_listener = pdl


def test():
    if os.path.exists("Current.pbpp"):
        import sys

        cd = os.path.dirname(os.path.realpath(__file__))
        up = os.path.realpath(cd + "/..")
        sys.path = [up,] + sys.path

        __wx__ = load("wxMSW")
        pdl = __wx__.ProcessingDoneListener()

        proj = Proj()
        proj.load("Current.pbpp")
        pdl.on_processing_done(proj.root_mod)


if __name__ == "__main__":
    test()
