
import sys
import re


def comment_out_enum(enum, content, beg):
    beg = content.find(enum, beg)
    if beg == -1:
        return content, -1
    
    end = content.index("};", beg) + 2
    content = content[:beg] + "/* " + content[beg:end] + " */" + content[end:]

    return content, end + 6


content = sys.stdin.read()
content = re.sub(r"\/\*.+?\*\/", "", content)


enums = (
    "enum wxAntialiasMode",
    "enum wxBitmapBufferFormat",
    "enum wxSoundFlags",
    "enum wxInterpolationQuality",
    "enum wxCompositionMode",
    "enum wxFindReplaceDialogStyles",
    "enum wxFindReplaceFlags",
)

for enum in enums:
    beg = 0
    while beg != -1:
        content, beg = comment_out_enum(enum, content, beg)


enums = (
    "enum wxTaskBarIconType",
)

for enum in enums:
    content, beg = comment_out_enum(enum, content, 0)


common_repl = (
    "enum { wxEXTEND_LAST_ON_EACH_LINE };",
    " = INT_MAX",
    "enum wxFontStyle;",
    "enum wxFontWeight;",
    "enum wxFontEncoding;",
    "enum wxFontFamily;",
    "wxTE_AUTO_SCROLL",
    "wxTINY_CAPTION_HORIZ",
    "wxTINY_CAPTION_VERT",
    "wxPYAPP_ASSERT_",
    "wxDEFAULT_STATUSBAR_STYLE",
    "wxDEFAULT_MINIFRAME_STYLE",
    "wxSPLASH_",
    "wxCURSOR_COPY_ARROW",
    "wxQUANTIZE_",
    "wxPD_",
    "wxTR_EXTENDED",  # TODO: new wxPython version?

    "wxBK_BUTTONBAR",
    "wxNB_",  # wxNotebook: let pbpp discover them
    "wxCHB_",  # TODO: wxChoicebook
    "wxLB_",  # TODO: wxListbook
    "wxTBK_",  # TODO: wxToolbook
)

for p in common_repl:
    content = content.replace(p, "// " + p)


print content
