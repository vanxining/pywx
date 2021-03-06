import os
import re

import Class
import Converters
import Module
import Registry


# noinspection PyMethodMayBeStatic
class WxPythonNamer(Module.PythonNamer):

    _wx_name_pattern = re.compile(r"(\W)wx([A-Z])")

    def package(self):
        return "wx"

    def _to_python(self, name):
        if name.startswith("wx"):
            name = name[2:]

        if '<' in name:
            name = self._wx_name_pattern.sub(r"\1\2", name)
            name = self.normalize_template(name)

        return name

    def pyobj(self, cls):
        name = self.to_python(cls)
        if name.islower():
            return "pseudo__" + name
        else:
            if '_' in name:
                return "Pseudo__" + name
            else:
                return "Pseudo" + name

    def pytype(self, cls):
        name = self.to_python(cls)
        if name.islower():
            return name + "__type"
        else:
            if '_' in name:
                return name + "__Type"
            else:
                return name + "Type"


# noinspection PyMethodMayBeStatic
class WxHeaderProvider(Module.HeaderProvider):
    def __init__(self):
        Module.HeaderProvider.__init__(self)

    _mappings = {
        "wxAppTraits": ("wx/apptrait.h",),
        "wxFontBase": ("wx/fontutil.h",),
        "wxFont": ("wx/fontutil.h",),
        "wxTextCompleter": ("wx/textcompleter.h",),
    }

    def klass(self, cls):
        headers = self._mappings.get(cls)
        if headers:
            return headers

        if cls.startswith("wxApp") or cls == "wxPyApp":
            return "wx/vidmode.h",
        else:
            return ()

    def module(self, name):
        if name == "wx":
            return ("wx/process.h",
                    "wx/clipbrd.h",)

        return ()

    def normalize(self, full_path):
        full_path = full_path.replace(os.path.sep, '/')
        full_path = full_path.replace("//", '/')

        pos = -1
        for subdir in ("/wx/", "/Adapters/", "/Hacks/",):
            pos = full_path.rfind(subdir)
            if pos != -1:
                break

        if pos == -1:
            pos = full_path.rindex('/')

        return full_path[(pos + 1):]

    def pch(self):
        return '#include "StdAfx.hpp"'


class WxFlagsAssigner(Module.FlagsAssigner):

    _managed_by_wx = [
        "wxWindow",
        "wxSizer",
        "wxXmlSubclassFactory",
        "wxMenuItem",
        "wxMenu",  # TODO:
        "wxDataObject",
    ]

    def assign(self, cls_name):
        cls = Registry.get_class(cls_name)

        for nonowned in self._managed_by_wx:
            if cls.full_name == nonowned or cls.is_derived_from(nonowned):
                return "pbpp::LifeTime::CXX"

        return "pbpp::LifeTime::PYTHON"


class WxBlacklist(Module.Blacklist):

    _namespaces = {
        "std", "stdext", "__gnu_cxx",
        "wxPrivate",
    }

    _class_patterns = (
        re.compile(r"wxEventTypeTag"),
        re.compile(r"(\w+::)*(const_)?(i|I)terator"),
        re.compile(r"\w*_class_type_info_pseudo\w*"),
        re.compile(r"\w+Hash(Map|Table)\w*"),
        re.compile(r"wx\w*Array"),
        re.compile(r"wx\w*Map"),
        re.compile(r"^\w+List(Node)?(Base)?$"),
        re.compile(r"wxImageHistogram\w*"),
        re.compile(r"wx[A-Z]+Handler"),  # wxPNGHandler etc.
        re.compile(r"wx\w*EventTable\w*"),
        re.compile(r"wxShadowObject\w*"),

        # TODO:
        re.compile(r"wxWeakRef.*"),
        re.compile(r"wxVector.*"),
    )

    _classes = {
        "PyObject",
        "_PySelf",

        "wxNodeBase",
        "wxMSGArray",
        "tagMSG",
        "wxEvtHandlerArray",

        "wxResourceCache",
        "wxBusyCursorSuspender",
        "wxDIB",

        "wxDCFactory",
        "wxNativeDCFactory",
        "wxDCImpl",
        "wxDC::TempHDC",
        "wxGCDCImpl",
        "wxTransform2D",
        "wxDrawObject",
        "wxEventFunctor",
        "wxObjectEventFunctor",
        "wxTrackerNode",
        "wxEventConnectionRef",
        "wxWindowCreationHook",
        "wxWindowBase::ChildrenRepositioningGuard",
        "wxTextEntryBase::EventsSuppressor",
        "wxStreamToTextRedirector",
        "wxMenuInvokingWindowSetter",

        "wxXmlResourceHandlerImpl",
    }

    _class_exceptions = {
        "wxImageList",
        "wxGDIObjListBase",
        "wxBrushList",
        "wxPenList",
        "wxFontList",
    }

    _base_patterns = ()
    _bases = {
        "std::basic_streambuf<char, std::char_traits<char> >",
        "_PySelf",
    }

    _common_method_patterns = (
        re.compile(r".+\WWXH[A-Z]+\W.*"),
        re.compile(r".+\WWXMSG\W.*"),

        re.compile(r".+\W(const )?wxString \*\W"),  # TODO: wxString *
        re.compile(r".+[^\w\s]\s*wxString &\W"),  # TODO: wxString &
    )

    # match at start
    _method_patterns = (
        re.compile(r"\W(begin|end)\W.+"),

        re.compile(r"[\w+:]*wxCreateObject\(\)"),
        re.compile(r".+::(Do)?MSW\w.+"),
        re.compile(r".+H[A-Z]+__.+"),
        re.compile(r".+GetH[A-Z].+"),
        re.compile(r".+Palette.+"),
        re.compile(r".+wxPixelDataBase.+"),
        re.compile(r".+wxDIB.+"),
        re.compile(r".+wxDeprecatedGUIConstants.+"),
        re.compile(r".+TransformMatrix.+"),
        re.compile(r".+Event(Hash)?Table.+"),
        re.compile(r"wxEvtHandler::(C|Disc)onnect.+"),
        re.compile(r"wxApp\w*::CleanUp\(\)"),  # use OnExit()
        re.compile(r".+wxCmdLineParser.+"),
    ) + _common_method_patterns

    _methods = {
        "wxClassInfo::begin_classinfo()",
        "wxClassInfo::end_classinfo()",
        "wxColourBase::ChangeLightness(unsigned char *, unsigned char *, unsigned char *, int)",
        "wxColourBase::MakeDisabled(unsigned char *, unsigned char *, unsigned char *, unsigned char)",
        "wxNativeFontInfo::wxNativeFontInfo(const LOGFONT &)",

        "wxImage::ComputeHistogram(wxImageHistogram &) const",
        "wxMask::GetMaskBitmap() const",
        "wxBitmap::GetBitmapData() const",
        "wxPen::Recreate()",

        # TODO: HDC
        "wxDC::GetImpl()",
        "wxDC::GetImpl() const",
        "wxDC::AcquireHDC()",
        "wxDC::GetTempHDC()",
        "wxDC::DrawObject(wxDrawObject *)",
        "wxDC::wxDC(wxDCImpl *)",
        "wxClientDC::wxClientDC(wxDCImpl *)",
        "wxWindowDC::wxWindowDC(wxDCImpl *)",
        "wxPaintDC::wxPaintDC(wxDCImpl *)",
        "wxGCDC::AcquireHDC()",

        "wxEvtHandler::FindRefInTrackerList(wxEvtHandler *)",
        "wxEvtHandler::GetEventHashTable() const",
        "wxWindowBase::GetConstraintsInvolvedIn() const",
        "wxFrame::GetDefaultIcon() const",

        "wxAppConsoleBase::HandleEvent(wxEvtHandler *, wxEventFunction, wxEvent &) const",
        "wxAppConsoleBase::CallEventHandler(wxEvtHandler *, wxEventFunctor &, wxEvent &) const",
        "wxApp::InitRichEdit(int)",  # TODO: wxMSW only?
        "wxPyApp::SetStartupComplete(bool)",

        "wxTreeCtrl::GetItemParam(const wxTreeItemId &) const",

        # TODO: incomplete support for function ptr (call convention)
        "wxListCtrl::SortItems(wxListCtrlCompare, wxIntPtr)",

        "wxDropFilesEvent::GetFiles() const",  # TODO: returns wxString *

        # excluede raw array editions
        "wxDC::DrawLines(int, const wxPoint *, int, int)",

        # static and non-static overloads
        # TODO: auto it?
        "wxTextEntryBase::SendTextUpdatedEvent(wxWindow *)",
        "wxTextAttr::Merge(const wxTextAttr &, const wxTextAttr &)",
        "wxControlBase::GetLabelText(const wxString &)",

        "wxRect2DInt::Intersect(const wxRect2DInt &, const wxRect2DInt &, wxRect2DInt *)",
        "wxRect2DInt::Union(const wxRect2DInt &, const wxRect2DInt &, wxRect2DInt *)",
        "wxRect2DDouble::Intersect(const wxRect2DDouble &, const wxRect2DDouble &, wxRect2DDouble *)",
        "wxRect2DDouble::Union(const wxRect2DDouble &, const wxRect2DDouble &, wxRect2DDouble *)",

        "wxWindowBase::FromDIP(const wxSize &, const wxWindowBase *)",
        "wxWindowBase::FromDIP(const wxPoint &, const wxWindowBase *)",
        "wxWindowBase::FromDIP(int, const wxWindowBase *)",

        "wxWindowBase::ToDIP(const wxSize &, const wxWindowBase *)",
        "wxWindowBase::ToDIP(const wxPoint &, const wxWindowBase *)",
        "wxWindowBase::ToDIP(int, const wxWindowBase *)",

        # TODO: wxDataInputStream / wxDataOutputStream
        "wxPoint2DInt::ReadFrom(wxDataInputStream &)",
        "wxPoint2DInt::WriteTo(wxDataOutputStream &) const",
        "wxRect2DInt::ReadFrom(wxDataInputStream &)",
        "wxRect2DInt::WriteTo(wxDataOutputStream &) const",

        # wxGraphicsMatrix, wxGraphicsMatrixData,
        # wxGraphicsBitmapData, wxGraphicsObjectRefData, wxGraphicsPathData
        "wxGraphicsContext::CreateMatrix(const wxAffineMatrix2DBase &) const",
        "wxGraphicsMatrix::GetMatrixData() const",
        "wxGraphicsMatrix::GetMatrixData()",
        "wxGraphicsBitmap::GetBitmapData() const",
        "wxGraphicsBitmap::GetBitmapData()",
        "wxGraphicsObject::GetGraphicsData() const",
        "wxGraphicsPath::GetPathData() const",
        "wxGraphicsPath::GetPathData()",

        # TODO: underfined reference?
        "wxPoint2DInt::SetPolarCoordinates(wxInt32, wxInt32)",
        "wxPoint2DDouble::SetPolarCoordinates(wxDouble, wxDouble)",

        # TODO: lack the wx28 compatibility checking macro
        "wxDC::SetClippingRegion(const wxRegion &)",
        "wxWindowBase::SetInitialBestSize(const wxSize &)",
        "wxWindowBase::SetBestFittingSize(const wxSize &)",
        "wxWindowBase::SetBestSize(const wxSize &)",
        "wxWindowBase::GetBestFittingSize() const",
        "wxWindowBase::GetAdjustedMinSize() const",

        # TODO:
        "wxDialogBase::CreateTextSizer(const wxString &, wxTextSizerWrapper &)",
        "wxMessageDialogBase::ButtonLabel::ButtonLabel(const wxCStrData &)",
        "wxDataFormat::wxDataFormat(const wxCStrData &)",

        # OLE
        "wxDataObject::GetInterface() const",

        # seem not implemented
        "wxChoice::Free()",
        "wxListBox::Free()",
        "wxMenuItemBase::GetAccelFromString(const wxString &)",
        "wxMenuBase::New(const wxString &, long)",

        # obsolete
        "wxBusyCursor::GetStoredCursor()",
        "wxBusyCursor::GetBusyCursor()",
    }

    _free_functions_patterns = (
        re.compile(r".+wxUnusedVar.+"),
        re.compile(r".+wxSwap.+"),
        re.compile(r".+Event\w*Functor.+"),
    ) + _common_method_patterns

    _free_functions = {
        "wxCreateApp()",
        "wxNewEventType()",
        "wxGetNativeFontEncoding(wxFontEncoding, wxNativeEncodingInfo *)",
        "wxTestFontEncoding(const wxNativeEncodingInfo &)",

        # seem not implemented
        "wxShell(const wxString &, wxArrayString &)",
        "wxFlushEvents()",

        # TODO:
        "wxGetLibraryVersionInfo()",
        "wxGetFreeMemory()",
        "wxGetDiskSpace(const wxString &, wxDiskspaceSize_t *, wxDiskspaceSize_t *)",
    }

    _return_type_patterns = (
        re.compile(r"wx(\w)*Sizer [*&]?"),  # TODO: Why?
    )

    _return_types = ()

    _global_constants_patterns = (
        re.compile(r"wxEventTypeTag\W"),
    )

    _global_constants = {
        "wxTheAppInitializer",  # a free function
        "wxPendingDelete",      # for compatibility purposes only
        "wxTopLevelWindows",    # no use currently
        "wxNullPalette",
    }

    _fields = {
        "wxAppConsoleBase::argc",
        "wxAppConsoleBase::argv",
        "wxGDIObjListBase::list",
        "wxNativeFontInfo::lf",
    }

    _simple_dummy_classes = (
        "HBRUSH__",
        "HDC__",
        "HMENU__",
        "HWND__",

        "wxToolTip",
        "wxScrollHelper",
        "wxDropTarget",
        "wxCaret",
        "wxDynamicEventTableEntry",
        "wxTrackerNode",
        "wxLayoutConstraints",

        "wxAcceleratorTable",
        "wxAcceleratorEntry",

        "wxAppTraits",
        "wxIconBundle",
        "wxTextCompleter",
        "wxScrolledWindow",
        "wxToolBar",
        "wxStaticBox",

        "wxEnhMetaFileDC",
        "wxPrinterDC",

        # wxListBox
        "wxArrayStringsAdapter",  # TODO: perhaps this is useful
        "wxArrayTreeItemIds",  # wxTreeCtrl

        # wxXmlResource
        "wxXmlResourceHandler",
        "wxXmlDocument",
        "wxXmlNode",
        "wxFileName",
    )

    def __init__(self):
        Module.Blacklist.__init__(self)

        for cls in self._simple_dummy_classes:
            self.add_simple_dummy_class(cls)

            if cls[0] == 'H' and cls.endswith("__"):
                self.dummy_classes[cls].is_struct = True

        self.dummy_classes["wxDynamicEventTableEntry"].is_struct = True

    def namespace(self, ns):
        return ns in self._namespaces

    def klass(self, cls):
        if cls in self._class_exceptions:
            return False

        for pattern in self._class_patterns:
            if pattern.match(cls):
                return True

        return cls in self._classes

    def base(self, full_name):
        for pattern in self._base_patterns:
            if pattern.match(full_name):
                return True

        return full_name in self._bases

    def method(self, mname):
        for pattern in self._method_patterns:
            if pattern.match(mname):
                return True

        return mname in self._methods

    def free_function(self, name):
        for pattern in self._free_functions_patterns:
            if pattern.match(name):
                return True

        return name in self._free_functions

    def return_type(self, ret):
        decl = ret.decl()

        for pattern in self._return_type_patterns:
            if pattern.match(decl):
                return True

        return decl in self._return_types

    def global_constants(self, full_decl_map):
        full_decl = "%s %s" % (full_decl_map["TYPE"], full_decl_map["FULL_NAME"])
        for pattern in self._global_constants_patterns:
            if pattern.match(full_decl):
                return True

        return full_decl_map["FULL_NAME"] in self._global_constants

    def field(self, cls, f):
        if f[0] == '_' or f[-1] == '_' or f.startswith("m_") or f[:3] in ("sm_", "ms_"):
            return True
        else:
            return cls + "::" + f in self._fields

    def hook_write(self, name, content):
        return content


class WxStringConv(Converters.Converter):
    def __init__(self):
        Converters.Converter.__init__(self)

    def match(self, cpp_type):
        if cpp_type.intrinsic_type() == "wxString":
            if not cpp_type.is_trivial():
                if cpp_type.is_const() or not cpp_type.has_decorators():
                    return True

        return False

    def specifier(self, cpp_type):
        return "u"

    def args_parsing_declare_vars(self, cpp_type, var_name, defv=None):
        init_expr = "nullptr"
        if defv is not None:
            init_expr = "(const wchar_t *) " + defv

        return "const wchar_t *%s = %s;" % (var_name, init_expr)

    def args_parsing_interim_vars(self, cpp_type, arg_name, pytype):
        return "&" + arg_name

    def args_parsing_extracting_code(self, cpp_type, arg_name, defv, error_return, namer):
        return ""

    def args_parsing_require_error_handling(self, cpp_type):
        return False

    def negative_checker(self, cpp_type, py_var_name):
        return "!PyUnicode_Check(%s)" % py_var_name

    def extracting_code(self, cpp_type, var_name, py_var_name, error_return, namer):
        # TODO: PyUnicode_AsUnicode() deprecated
        return cpp_type.declare_var(var_name, "PyUnicode_AsUnicode(%s)" % py_var_name)

    def build(self, cpp_type, var_name, py_var_name, namer, raii):
        common_part = "PyUnicode_FromWideChar({1}.wx_str(), {1}.length())"
        boilerplate = "pbpp::PyObjectPtr {{0}}({});" if raii else "PyObject *{{0}} = {};"

        return boilerplate.format(common_part).format(py_var_name, var_name)


class WxListConv(Converters.ListConv):
    def __init__(self, T, wx_type_name):
        Converters.ListConv.__init__(self, T)
        self.wx_type_name = wx_type_name

    def match(self, cpp_type):
        if not cpp_type.is_trivial():
            if cpp_type.intrinsic_type() == self.wx_type_name:
                return True

        return Converters.ListConv.match(self, cpp_type)


class WxDictConv(Converters.DictConv):
    def __init__(self, K, V, wx_type_name):
        Converters.DictConv.__init__(self, K, V)
        self.wx_type_name = wx_type_name

    def match(self, cpp_type):
        if not cpp_type.is_trivial():
            if cpp_type.intrinsic_type() == self.wx_type_name:
                return True

        return Converters.DictConv.match(self, cpp_type)


# noinspection PyMethodMayBeStatic
class ProcessingDoneListener:
    def __init__(self):
        pass

    def on_processing_done(self, module):
        self._handle_headers(module)
        self._handle_global_constants(module)
        self._handle_argument_default_values(module)
        self._inject_methods(module)

    def _handle_headers(self, module):
        # Module level

        headers = set()
        discard = set()

        for header in module.header_jar.headers:
            if "/msw/" not in header and "Hacks/" not in header:
                if header not in discard:
                    headers.add(header)

        module.header_jar.headers = list(headers)

        # Class level

        classes = {
            "wxGUIEventLoop": "wx/msw/evtloop.h",
            "wxListCtrl": "wx/msw/listctrl.h",
            "wxTreeCtrl": "wx/msw/treectrl.h",
            "wxNotebook": "wx/msw/notebook.h",
            "wxClipboard": "wx/msw/clipbrd.h",
        }

        for name in classes:
            cls = Registry.get_class(name)
            if cls:
                cls.header_jar.remove_header('#include "%s"' % classes[name])
                cls.header_jar.add_headers((classes[name].replace("/msw", ""),))

        for name in ("wxMSWEventLoopBase", "wxConsoleEventLoop",):
            cls = Registry.get_class(name)
            if cls:
                cls.header_jar.remove_header('#include "wx/msw/evtloopconsole.h"')
                cls.header_jar.add_headers(("wx/evtloop.h",))

    def _handle_global_constants(self, module):
        import Types, Argument

        dummy_type = Types.Type(("wxClipboard", "*",), 999, "Class")
        wxTheClipboard = Argument.Argument(dummy_type, "wxTheClipboard")
        module.global_constants["wxTheClipboard"] = wxTheClipboard

    def _handle_argument_default_values(self, module):
        wxWindowBase = Registry.get_class("wxWindowBase")
        if wxWindowBase:
            for mname in ("NavigateIn", "Navigate",):
                overloads = wxWindowBase.methods.methods[mname]
                assert len(overloads) == 1

                arg = overloads[0].args.args[0]
                arg.defv = "wxNavigationKeyEvent::IsForward"

    def _inject_methods(self, module):
        # TODO: Add support for reparsing one single file

        class Injection(object):
            def __init__(self, **kwargs):
                self.__dict__.update(kwargs)

        inj = (
            Injection(cxx_name="wxPyBind",
                      py_name="Bind",
                      headers=("Adapters/PyBind.hxx",),
                      classes=("wxEvtHandler",)),

            Injection(cxx_name="wxPyUnbind",
                      py_name="Unbind",
                      headers=("Adapters/PyBind.hxx",),
                      classes=("wxEvtHandler",)),

            Injection(cxx_name="TextEntryBase_GetSelection",
                      py_name="GetSelection",
                      headers=("Adapters/More.hxx",),
                      classes=("wxTextEntryBase", "wxTextEntry", "wxTextCtrl",)),

            Injection(cxx_name="OutputStream_Write",
                      py_name="Write",
                      headers=("Adapters/More.hxx",),
                      classes=("wxOutputStream", "wxBufferedOutputStream",)),

            Injection(cxx_name="InputStream_Read",
                      py_name="Read",
                      headers=("Adapters/More.hxx",),
                      classes=("wxInputStream", "wxBufferedInputStream",)),

            Injection(cxx_name="DropFilesEvent_GetFiles",
                      py_name="GetFiles",
                      headers=("Adapters/More.hxx",),
                      classes=("wxDropFilesEvent",)),
        )

        for m in inj:
            ff = module.free_functions.methods.pop(m.cxx_name, None)
            if ff:
                for cls_name in m.classes:
                    cls = Registry.get_class(cls_name)
                    cls.inject_as_method(ff, m.py_name, m.headers)
