#ifdef __CASTXML__

// _sizers.i
// enum { wxEXTEND_LAST_ON_EACH_LINE };
// _sizers.i
enum wxFlexSizerGrowMode {
    wxFLEX_GROWMODE_NONE,
    wxFLEX_GROWMODE_SPECIFIED,
    wxFLEX_GROWMODE_ALL
};

// _statctrls.i
enum {
    wxST_NO_AUTORESIZE,
    wxST_ELLIPSIZE_START,
    wxST_ELLIPSIZE_MIDDLE,
    wxST_ELLIPSIZE_END
};

// _statusbar.i
enum {
    wxSTB_SIZEGRIP,
    wxSTB_SHOW_TIPS,
    wxSTB_ELLIPSIZE_START,
    wxSTB_ELLIPSIZE_MIDDLE,
    wxSTB_ELLIPSIZE_END,
    wxSTB_DEFAULT_STYLE,
    wxST_SIZEGRIP,
};

// _statusbar.i
enum {
    wxSB_NORMAL,
    wxSB_FLAT,
    wxSB_RAISED
};

// _stockobjs.i
enum Item {
};

// _streams.i
enum wxSeekMode {
    wxFromStart,
    wxFromCurrent,
    wxFromEnd
};

// _textctrl.i
enum {
    wxTE_NO_VSCROLL,
    // wxTE_AUTO_SCROLL,
    wxTE_READONLY,
    wxTE_MULTILINE,
    wxTE_PROCESS_TAB,
    wxTE_LEFT,
    wxTE_CENTER,
    wxTE_RIGHT,
    wxTE_CENTRE,
    wxTE_RICH,
    wxTE_PROCESS_ENTER,
    wxTE_PASSWORD,
    wxTE_AUTO_URL,
    wxTE_NOHIDESEL,
    wxTE_DONTWRAP,
    wxTE_CHARWRAP,
    wxTE_WORDWRAP,
    wxTE_BESTWRAP,
    wxTE_RICH2,
    wxTE_CAPITALIZE,
};

// _textctrl.i
enum wxTextAttrAlignment {
    wxTEXT_ALIGNMENT_DEFAULT,
    wxTEXT_ALIGNMENT_LEFT,
    wxTEXT_ALIGNMENT_CENTRE,
    wxTEXT_ALIGNMENT_CENTER = wxTEXT_ALIGNMENT_CENTRE,
    wxTEXT_ALIGNMENT_RIGHT,
    wxTEXT_ALIGNMENT_JUSTIFIED
};

// _textctrl.i
enum wxTextAttrFlags {
    wxTEXT_ATTR_TEXT_COLOUR,
    wxTEXT_ATTR_BACKGROUND_COLOUR,
    wxTEXT_ATTR_FONT_FACE,
    wxTEXT_ATTR_FONT_SIZE,
    wxTEXT_ATTR_FONT_WEIGHT,
    wxTEXT_ATTR_FONT_ITALIC,
    wxTEXT_ATTR_FONT_UNDERLINE,
    wxTEXT_ATTR_FONT_STRIKETHROUGH,
    wxTEXT_ATTR_FONT_ENCODING,
    wxTEXT_ATTR_FONT_FAMILY,
    wxTEXT_ATTR_FONT,
    wxTEXT_ATTR_ALIGNMENT,
    wxTEXT_ATTR_LEFT_INDENT,
    wxTEXT_ATTR_RIGHT_INDENT,
    wxTEXT_ATTR_TABS,
    wxTEXT_ATTR_PARA_SPACING_AFTER,
    wxTEXT_ATTR_LINE_SPACING,
    wxTEXT_ATTR_CHARACTER_STYLE_NAME,
    wxTEXT_ATTR_PARAGRAPH_STYLE_NAME,
    wxTEXT_ATTR_LIST_STYLE_NAME,
    wxTEXT_ATTR_BULLET_STYLE,
    wxTEXT_ATTR_BULLET_NUMBER,
    wxTEXT_ATTR_BULLET_TEXT,
    wxTEXT_ATTR_BULLET_NAME,
    wxTEXT_ATTR_BULLET,
    wxTEXT_ATTR_URL,
    wxTEXT_ATTR_PAGE_BREAK,
    wxTEXT_ATTR_EFFECTS,
    wxTEXT_ATTR_OUTLINE_LEVEL,
    wxTEXT_ATTR_CHARACTER,
    wxTEXT_ATTR_PARAGRAPH,
    wxTEXT_ATTR_ALL,
};

// _textctrl.i
enum wxTextAttrBulletStyle {
    wxTEXT_ATTR_BULLET_STYLE_NONE,
    wxTEXT_ATTR_BULLET_STYLE_ARABIC,
    wxTEXT_ATTR_BULLET_STYLE_LETTERS_UPPER,
    wxTEXT_ATTR_BULLET_STYLE_LETTERS_LOWER,
    wxTEXT_ATTR_BULLET_STYLE_ROMAN_UPPER,
    wxTEXT_ATTR_BULLET_STYLE_ROMAN_LOWER,
    wxTEXT_ATTR_BULLET_STYLE_SYMBOL,
    wxTEXT_ATTR_BULLET_STYLE_BITMAP,
    wxTEXT_ATTR_BULLET_STYLE_PARENTHESES,
    wxTEXT_ATTR_BULLET_STYLE_PERIOD,
    wxTEXT_ATTR_BULLET_STYLE_STANDARD,
    wxTEXT_ATTR_BULLET_STYLE_RIGHT_PARENTHESIS,
    wxTEXT_ATTR_BULLET_STYLE_OUTLINE,
    wxTEXT_ATTR_BULLET_STYLE_ALIGN_LEFT,
    wxTEXT_ATTR_BULLET_STYLE_ALIGN_RIGHT,
    wxTEXT_ATTR_BULLET_STYLE_ALIGN_CENTRE,
};

// _textctrl.i
enum wxTextAttrEffects {
    wxTEXT_ATTR_EFFECT_NONE,
    wxTEXT_ATTR_EFFECT_CAPITALS,
    wxTEXT_ATTR_EFFECT_SMALL_CAPITALS,
    wxTEXT_ATTR_EFFECT_STRIKETHROUGH,
    wxTEXT_ATTR_EFFECT_DOUBLE_STRIKETHROUGH,
    wxTEXT_ATTR_EFFECT_SHADOW,
    wxTEXT_ATTR_EFFECT_EMBOSS,
    wxTEXT_ATTR_EFFECT_OUTLINE,
    wxTEXT_ATTR_EFFECT_ENGRAVE,
    wxTEXT_ATTR_EFFECT_SUPERSCRIPT,
    wxTEXT_ATTR_EFFECT_SUBSCRIPT,
};

// _textctrl.i
enum wxTextAttrLineSpacing {
    wxTEXT_ATTR_LINE_SPACING_NORMAL,
    wxTEXT_ATTR_LINE_SPACING_HALF,
    wxTEXT_ATTR_LINE_SPACING_TWICE,
};

// _textctrl.i
enum {
    wxOutOfRangeTextCoord,
    wxInvalidTextCoord,
    wxTEXT_TYPE_ANY
};

// _textctrl.i
// enum wxFontStyle;
// _textctrl.i
// enum wxFontWeight;
// _textctrl.i
// enum wxFontEncoding;
// _textctrl.i
// enum wxFontFamily;
// _timer.i
enum {
    wxTIMER_CONTINUOUS,
    wxTIMER_ONE_SHOT,
};

// _toplvl.i
enum {
    wxSTAY_ON_TOP,
    wxICONIZE,
    wxMINIMIZE,
    wxMAXIMIZE,
    wxCLOSE_BOX,
    wxSYSTEM_MENU,
    wxMINIMIZE_BOX,
    wxMAXIMIZE_BOX,
    // wxTINY_CAPTION_HORIZ,
    // wxTINY_CAPTION_VERT,
    wxRESIZE_BORDER,
    wxDIALOG_NO_PARENT,
    wxDEFAULT_FRAME_STYLE,
    wxDEFAULT_DIALOG_STYLE,
    wxFRAME_TOOL_WINDOW,
    wxFRAME_FLOAT_ON_PARENT,
    wxFRAME_NO_WINDOW_MENU,
    wxFRAME_NO_TASKBAR,
    wxFRAME_SHAPED,
    wxFRAME_DRAWER,
    wxFRAME_EX_METAL,
    wxDIALOG_EX_METAL,
    wxWS_EX_CONTEXTHELP,
    wxFRAME_EX_CONTEXTHELP,
    wxDIALOG_EX_CONTEXTHELP,
};

// _toplvl.i
enum {
    wxFULLSCREEN_NOMENUBAR,
    wxFULLSCREEN_NOTOOLBAR,
    wxFULLSCREEN_NOSTATUSBAR,
    wxFULLSCREEN_NOBORDER,
    wxFULLSCREEN_NOCAPTION,
    wxFULLSCREEN_ALL,
    wxTOPLEVEL_EX_DIALOG,
};

// _toplvl.i
enum {
    wxUSER_ATTENTION_INFO = 1,
    wxUSER_ATTENTION_ERROR = 2
};

// _toplvl.i
enum wxDialogModality {
    wxDIALOG_MODALITY_NONE = 0,
    wxDIALOG_MODALITY_WINDOW_MODAL = 1,
    wxDIALOG_MODALITY_APP_MODAL = 2
};

// _toplvl.i
enum {
    wxDIALOG_ADAPTATION_NONE,
    wxDIALOG_ADAPTATION_STANDARD_SIZER,
    wxDIALOG_ADAPTATION_ANY_SIZER,
    wxDIALOG_ADAPTATION_LOOSE_BUTTONS,
};

// _toplvl.i
enum wxDialogLayoutAdaptationMode {
    wxDIALOG_ADAPTATION_MODE_DEFAULT = 0,   // use global adaptation enabled status
    wxDIALOG_ADAPTATION_MODE_ENABLED = 1,   // enable this dialog overriding global status
    wxDIALOG_ADAPTATION_MODE_DISABLED = 2   // disable this dialog overriding global status
};

// _toplvl.i
enum  {
    // wxDEFAULT_MINIFRAME_STYLE
};

// _toplvl.i
enum {
    // wxSPLASH_CENTRE_ON_PARENT,
    // wxSPLASH_CENTRE_ON_SCREEN,
    // wxSPLASH_NO_CENTRE,
    // wxSPLASH_CENTER_ON_PARENT,
    // wxSPLASH_CENTER_ON_SCREEN,
    // wxSPLASH_NO_CENTER,
    // wxSPLASH_TIMEOUT,
    // wxSPLASH_NO_TIMEOUT,
};

// _treectrl.i
enum {
    wxTR_NO_BUTTONS,
    wxTR_HAS_BUTTONS,
    wxTR_NO_LINES,
    wxTR_LINES_AT_ROOT,
    wxTR_SINGLE,
    wxTR_MULTIPLE,
    // wxTR_EXTENDED,
    wxTR_HAS_VARIABLE_ROW_HEIGHT,
    wxTR_EDIT_LABELS,
    wxTR_HIDE_ROOT,
    wxTR_ROW_LINES,
    wxTR_FULL_ROW_HIGHLIGHT,
    wxTR_DEFAULT_STYLE,
    wxTR_TWIST_BUTTONS,
};

// _treectrl.i
enum wxTreeItemIcon {
    wxTreeItemIcon_Normal,              // not selected, not expanded
    wxTreeItemIcon_Selected,            //     selected, not expanded
    wxTreeItemIcon_Expanded,            // not selected,     expanded
    wxTreeItemIcon_SelectedExpanded,    //     selected,     expanded
    wxTreeItemIcon_Max
};

// _treectrl.i
enum {
    wxTREE_ITEMSTATE_NONE,    // not state (no display state image)
    wxTREE_ITEMSTATE_NEXT,    // cycle to the next state
    wxTREE_ITEMSTATE_PREV     // cycle to the previous state
};

// _treectrl.i
enum {
    wxTREE_HITTEST_ABOVE,
    wxTREE_HITTEST_BELOW,
    wxTREE_HITTEST_NOWHERE,
    wxTREE_HITTEST_ONITEMBUTTON,
    wxTREE_HITTEST_ONITEMICON,
    wxTREE_HITTEST_ONITEMINDENT,
    wxTREE_HITTEST_ONITEMLABEL,
    wxTREE_HITTEST_ONITEMRIGHT,
    wxTREE_HITTEST_ONITEMSTATEICON,
    wxTREE_HITTEST_TOLEFT,
    wxTREE_HITTEST_TORIGHT,
    wxTREE_HITTEST_ONITEMUPPERPART,
    wxTREE_HITTEST_ONITEMLOWERPART,
    wxTREE_HITTEST_ONITEM
};

// _window.i
enum wxWindowVariant {
    wxWINDOW_VARIANT_NORMAL,        // Normal size
    wxWINDOW_VARIANT_SMALL,         // Smaller size (about 25 % smaller than normal )
    wxWINDOW_VARIANT_MINI,          // Mini size (about 33 % smaller than normal )
    wxWINDOW_VARIANT_LARGE,         // Large size (about 25 % larger than normal )
    wxWINDOW_VARIANT_MAX
};

// _window.i
enum wxShowEffect {
    wxSHOW_EFFECT_NONE,
    wxSHOW_EFFECT_ROLL_TO_LEFT,
    wxSHOW_EFFECT_ROLL_TO_RIGHT,
    wxSHOW_EFFECT_ROLL_TO_TOP,
    wxSHOW_EFFECT_ROLL_TO_BOTTOM,
    wxSHOW_EFFECT_SLIDE_TO_LEFT,
    wxSHOW_EFFECT_SLIDE_TO_RIGHT,
    wxSHOW_EFFECT_SLIDE_TO_TOP,
    wxSHOW_EFFECT_SLIDE_TO_BOTTOM,
    wxSHOW_EFFECT_BLEND,
    wxSHOW_EFFECT_EXPAND,
    wxSHOW_EFFECT_MAX
};

// _window.i
enum {
    wxSEND_EVENT_POST = 1
};

// _withimages.i
enum {
};

// _xmlres.i
enum {
};

// _xmlres.i
enum wxXmlResourceFlags {
    wxXRC_USE_LOCALE,
    wxXRC_NO_SUBCLASSING,
    wxXRC_NO_RELOADING
};

// _app.i
enum {
    // wxPYAPP_ASSERT_SUPPRESS  = 1,
    // wxPYAPP_ASSERT_EXCEPTION = 2,
    // wxPYAPP_ASSERT_DIALOG    = 4,
    // wxPYAPP_ASSERT_LOG       = 8
};

// _app.i
enum {
    wxPRINT_WINDOWS = 1,
    wxPRINT_POSTSCRIPT = 2
};

// _bitmap.i
/* enum wxBitmapBufferFormat {
    wxBitmapBufferFormat_RGB,
    wxBitmapBufferFormat_RGBA,
    wxBitmapBufferFormat_RGB32,
    wxBitmapBufferFormat_ARGB32
}; */

// _bitmap.i
/* enum wxBitmapBufferFormat {
    wxBitmapBufferFormat_RGB,
    wxBitmapBufferFormat_RGBA,
    wxBitmapBufferFormat_RGB32,
    wxBitmapBufferFormat_ARGB32,
}; */

// _bitmap.i
enum {
    wxBITMAP_SCREEN_DEPTH
};

// _bookctrl.i
enum {
    wxBK_DEFAULT,
    wxBK_TOP,
    wxBK_BOTTOM,
    wxBK_LEFT,
    wxBK_RIGHT,
    wxBK_ALIGN_MASK,
    // wxBK_BUTTONBAR,   // deprecated
    // wxTBK_BUTTONBAR,
    // wxTBK_HORZ_LAYOUT,
    wxBK_HITTEST_NOWHERE = 1,   // not on tab
    wxBK_HITTEST_ONICON  = 2,   // on icon
    wxBK_HITTEST_ONLABEL = 4,   // on label
    wxBK_HITTEST_ONITEM  = wxBK_HITTEST_ONICON | wxBK_HITTEST_ONLABEL,
    wxBK_HITTEST_ONPAGE  = 8,   // not on tab control, but over the selected page
};

// _brush.i
enum wxBrushStyle {
    wxBRUSHSTYLE_INVALID,
    wxBRUSHSTYLE_SOLID,
    wxBRUSHSTYLE_TRANSPARENT,
    wxBRUSHSTYLE_STIPPLE_MASK_OPAQUE,
    wxBRUSHSTYLE_STIPPLE_MASK,
    wxBRUSHSTYLE_STIPPLE,
    wxBRUSHSTYLE_BDIAGONAL_HATCH,
    wxBRUSHSTYLE_CROSSDIAG_HATCH,
    wxBRUSHSTYLE_FDIAGONAL_HATCH,
    wxBRUSHSTYLE_CROSS_HATCH,
    wxBRUSHSTYLE_HORIZONTAL_HATCH,
    wxBRUSHSTYLE_VERTICAL_HATCH,
    wxBRUSHSTYLE_FIRST_HATCH,
    wxBRUSHSTYLE_LAST_HATCH,
};

// _button.i
enum {
    wxBU_LEFT,
    wxBU_TOP,
    wxBU_RIGHT,
    wxBU_BOTTOM,
    wxBU_ALIGN_MASK,
    wxBU_EXACTFIT,
    wxBU_AUTODRAW,
    wxBU_NOTEXT,
};

// _checkbox.i
enum {
    wxCHK_2STATE,
    wxCHK_3STATE,
    wxCHK_ALLOW_3RD_STATE_FOR_USER,
};

// _cmndlgs.i
enum {
};

// _cmndlgs.i
enum {
    wxDD_CHANGE_DIR,
    wxDD_DIR_MUST_EXIST,
    wxDD_NEW_DIR_BUTTON,
    wxDD_DEFAULT_STYLE,
};

// _cmndlgs.i
enum {
    wxFD_OPEN,
    wxFD_SAVE,
    wxFD_OVERWRITE_PROMPT,
    wxFD_FILE_MUST_EXIST,
    wxFD_MULTIPLE,
    wxFD_CHANGE_DIR,
    wxFD_PREVIEW,
    wxFD_DEFAULT_STYLE,
};

// _cmndlgs.i
enum { wxCHOICEDLG_STYLE };
// _cmndlgs.i
enum { wxTextEntryDialogStyle };
// _cmndlgs.i
enum {
    // wxPD_CAN_ABORT,
    // wxPD_APP_MODAL,
    // wxPD_AUTO_HIDE,
    // wxPD_ELAPSED_TIME,
    // wxPD_ESTIMATED_TIME,
    // wxPD_SMOOTH,
    // wxPD_REMAINING_TIME,
    // wxPD_CAN_SKIP,
};

// _cmndlgs.i
/* enum wxFindReplaceFlags {
    wxFR_DOWN       = 1,
    wxFR_WHOLEWORD  = 2,
    wxFR_MATCHCASE  = 4
}; */

// _cmndlgs.i
/* enum wxFindReplaceDialogStyles {
    wxFR_REPLACEDIALOG = 1,
    wxFR_NOUPDOWN      = 2,
    wxFR_NOMATCHCASE   = 4,
    wxFR_NOWHOLEWORD   = 8
}; */

// _colour.i
enum {
    wxC2S_NAME,             // return colour name, when possible
    wxC2S_CSS_SYNTAX,       // return colour in rgb(r,g,b) syntax
    wxC2S_HTML_SYNTAX,      // return colour in #rrggbb syntax
};

// _colour.i
enum {
    wxALPHA_TRANSPARENT,
    wxALPHA_OPAQUE
};

// _control.i
enum wxEllipsizeFlags {
    wxELLIPSIZE_FLAGS_NONE,
    wxELLIPSIZE_FLAGS_PROCESS_MNEMONICS,
    wxELLIPSIZE_FLAGS_EXPAND_TABS,
    wxELLIPSIZE_FLAGS_DEFAULT,
};

// _control.i
enum wxEllipsizeMode {
    wxELLIPSIZE_NONE,
    wxELLIPSIZE_START,
    wxELLIPSIZE_MIDDLE,
    wxELLIPSIZE_END
};

// _control.i
enum wxTextCtrlHitTestResult {
    wxTE_HT_UNKNOWN = -2,   // this means HitTest() is simply not implemented
    wxTE_HT_BEFORE,         // either to the left or upper
    wxTE_HT_ON_TEXT,        // directly on
    wxTE_HT_BELOW,          // below [the last line]
    wxTE_HT_BEYOND          // after [the end of line]
};

// _dataobj.i
enum wxDataFormatId {
    wxDF_INVALID,
    wxDF_TEXT,
    wxDF_BITMAP,
    wxDF_METAFILE,
    wxDF_SYLK,
    wxDF_DIF,
    wxDF_TIFF,
    wxDF_OEMTEXT,
    wxDF_DIB,
    wxDF_PALETTE,
    wxDF_PENDATA,
    wxDF_RIFF,
    wxDF_WAVE,
    wxDF_UNICODETEXT,
    wxDF_ENHMETAFILE,
    wxDF_FILENAME,
    wxDF_LOCALE,
    wxDF_PRIVATE,
    wxDF_HTML,
    wxDF_MAX,
};

// _dataobj.i
enum Direction {
};

// _dc.i
enum wxRasterOperationMode {
    wxCLEAR,       // 0
    wxXOR,         // src XOR dst
    wxINVERT,      // NOT dst
    wxOR_REVERSE,  // src OR (NOT dst)
    wxAND_REVERSE, // src AND (NOT dst)
    wxCOPY,        // src
    wxAND,         // src AND dst
    wxAND_INVERT,  // (NOT src) AND dst
    wxNO_OP,       // dst
    wxNOR,         // (NOT src) AND (NOT dst)
    wxEQUIV,       // (NOT src) XOR dst
    wxSRC_INVERT,  // (NOT src)
    wxOR_INVERT,   // (NOT src) OR dst
    wxNAND,        // (NOT src) OR (NOT dst)
    wxOR,          // src OR dst
    wxSET          // 1
};

// _dc.i
enum wxFloodFillStyle {
    wxFLOOD_SURFACE = 1,
    wxFLOOD_BORDER
};

// _dc.i
enum wxMappingMode {
    wxMM_TEXT = 1,
    wxMM_TWIPS,
    wxMM_POINTS,
    wxMM_METRIC
};

// _dc.i
enum {
    wxBUFFER_VIRTUAL_AREA,
    wxBUFFER_CLIENT_AREA,
    wxBUFFER_USES_SHARED_BUFFER
};

// _defs.i
enum {
    wxDefaultCoord,
    wxNOT_FOUND,
    wxNO_LEN,
    wxVSCROLL,
    wxHSCROLL,
    wxCAPTION,
    wxDOUBLE_BORDER,
    wxSUNKEN_BORDER,
    wxRAISED_BORDER,
    wxBORDER,
    wxSIMPLE_BORDER,
    wxSTATIC_BORDER,
    wxTRANSPARENT_WINDOW,
    wxNO_BORDER,
    wxDEFAULT_CONTROL_BORDER,
    // wxDEFAULT_STATUSBAR_STYLE,
    wxTAB_TRAVERSAL,
    wxWANTS_CHARS,
    wxPOPUP_WINDOW,
    wxCENTER_FRAME,
    wxCENTRE_ON_SCREEN,
    wxCENTER_ON_SCREEN,
    wxCLIP_CHILDREN,
    wxCLIP_SIBLINGS,
    wxWINDOW_STYLE_MASK,
    wxALWAYS_SHOW_SB,
    wxRETAINED,
    wxBACKINGSTORE,
    wxCOLOURED,
    wxFIXED_LENGTH,
    // wxLB_NEEDED_SB,
    // wxLB_ALWAYS_SB,
    // wxLB_SORT,
    // wxLB_SINGLE,
    // wxLB_MULTIPLE,
    // wxLB_EXTENDED,
    // wxLB_OWNERDRAW,
    // wxLB_HSCROLL,
    wxCB_SIMPLE,
    wxCB_DROPDOWN,
    wxCB_SORT,
    wxCB_READONLY,
    wxRA_HORIZONTAL,
    wxRA_VERTICAL,
    wxRA_SPECIFY_ROWS,
    wxRA_SPECIFY_COLS,
    wxRB_GROUP,
    wxRB_SINGLE,
    wxSB_HORIZONTAL,
    wxSB_VERTICAL,
    wxTOOL_TOP,
    wxTOOL_BOTTOM,
    wxTOOL_LEFT,
    wxTOOL_RIGHT,
    wxOK,
    wxYES_NO,
    wxCANCEL,
    wxYES,
    wxNO,
    wxNO_DEFAULT,
    wxYES_DEFAULT,
    wxOK_DEFAULT,
    wxCANCEL_DEFAULT,
    wxAPPLY,
    wxCLOSE,
    wxICON_EXCLAMATION,
    wxICON_HAND,
    wxICON_QUESTION,
    wxICON_INFORMATION,
    wxICON_STOP,
    wxICON_ASTERISK,
    wxICON_MASK,
    wxICON_WARNING,
    wxICON_ERROR,
    wxICON_NONE,
    wxFORWARD,
    wxBACKWARD,
    wxRESET,
    wxHELP,
    wxMORE,
    wxSETUP,
    wxSIZE_AUTO_WIDTH,
    wxSIZE_AUTO_HEIGHT,
    wxSIZE_AUTO,
    wxSIZE_USE_EXISTING,
    wxSIZE_ALLOW_MINUS_ONE,
    wxSIZE_FORCE,
    wxSIZE_FORCE_EVENT,
    wxPRINT_QUALITY_HIGH,
    wxPRINT_QUALITY_MEDIUM,
    wxPRINT_QUALITY_LOW,
    wxPRINT_QUALITY_DRAFT,
    wxID_AUTO_LOWEST,
    wxID_AUTO_HIGHEST,
    wxID_ANY,
    wxID_SEPARATOR,
    wxID_NONE,
    wxID_LOWEST,
    wxID_OPEN,
    wxID_CLOSE,
    wxID_NEW,
    wxID_SAVE,
    wxID_SAVEAS,
    wxID_REVERT,
    wxID_EXIT,
    wxID_UNDO,
    wxID_REDO,
    wxID_HELP,
    wxID_PRINT,
    wxID_PRINT_SETUP,
    wxID_PAGE_SETUP,
    wxID_PREVIEW,
    wxID_ABOUT,
    wxID_HELP_CONTENTS,
    wxID_HELP_COMMANDS,
    wxID_HELP_PROCEDURES,
    wxID_HELP_CONTEXT,
    wxID_HELP_INDEX,
    wxID_HELP_SEARCH,
    wxID_CLOSE_ALL,
    wxID_PREFERENCES,
    wxID_EDIT,
    wxID_CUT,
    wxID_COPY,
    wxID_PASTE,
    wxID_CLEAR,
    wxID_FIND,
    wxID_DUPLICATE,
    wxID_SELECTALL,
    wxID_DELETE,
    wxID_REPLACE,
    wxID_REPLACE_ALL,
    wxID_PROPERTIES,
    wxID_VIEW_DETAILS,
    wxID_VIEW_LARGEICONS,
    wxID_VIEW_SMALLICONS,
    wxID_VIEW_LIST,
    wxID_VIEW_SORTDATE,
    wxID_VIEW_SORTNAME,
    wxID_VIEW_SORTSIZE,
    wxID_VIEW_SORTTYPE,
    wxID_FILE,
    wxID_FILE1,
    wxID_FILE2,
    wxID_FILE3,
    wxID_FILE4,
    wxID_FILE5,
    wxID_FILE6,
    wxID_FILE7,
    wxID_FILE8,
    wxID_FILE9,
    wxID_OK,
    wxID_CANCEL,
    wxID_APPLY,
    wxID_YES,
    wxID_NO,
    wxID_STATIC,
    wxID_FORWARD,
    wxID_BACKWARD,
    wxID_DEFAULT,
    wxID_MORE,
    wxID_SETUP,
    wxID_RESET,
    wxID_CONTEXT_HELP,
    wxID_YESTOALL,
    wxID_NOTOALL,
    wxID_ABORT,
    wxID_RETRY,
    wxID_IGNORE,
    wxID_ADD,
    wxID_REMOVE,
    wxID_UP,
    wxID_DOWN,
    wxID_HOME,
    wxID_REFRESH,
    wxID_STOP,
    wxID_INDEX,
    wxID_BOLD,
    wxID_ITALIC,
    wxID_JUSTIFY_CENTER,
    wxID_JUSTIFY_FILL,
    wxID_JUSTIFY_RIGHT,
    wxID_JUSTIFY_LEFT,
    wxID_UNDERLINE,
    wxID_INDENT,
    wxID_UNINDENT,
    wxID_ZOOM_100,
    wxID_ZOOM_FIT,
    wxID_ZOOM_IN,
    wxID_ZOOM_OUT,
    wxID_UNDELETE,
    wxID_REVERT_TO_SAVED,
    wxID_CDROM,
    wxID_CONVERT,
    wxID_EXECUTE,
    wxID_FLOPPY,
    wxID_HARDDISK,
    wxID_BOTTOM,
    wxID_FIRST,
    wxID_LAST,
    wxID_TOP,
    wxID_INFO,
    wxID_JUMP_TO,
    wxID_NETWORK,
    wxID_SELECT_COLOR,
    wxID_SELECT_FONT,
    wxID_SORT_ASCENDING,
    wxID_SORT_DESCENDING,
    wxID_SPELL_CHECK,
    wxID_STRIKETHROUGH,
    wxID_SYSTEM_MENU,
    wxID_CLOSE_FRAME,
    wxID_MOVE_FRAME,
    wxID_RESIZE_FRAME,
    wxID_MAXIMIZE_FRAME,
    wxID_ICONIZE_FRAME,
    wxID_RESTORE_FRAME,
    wxID_MDI_WINDOW_FIRST,
    wxID_MDI_WINDOW_CASCADE,
    wxID_MDI_WINDOW_TILE_HORZ,
    wxID_MDI_WINDOW_TILE_VERT,
    wxID_MDI_WINDOW_ARRANGE_ICONS,
    wxID_MDI_WINDOW_PREV,
    wxID_MDI_WINDOW_NEXT,
    wxID_MDI_WINDOW_LAST,
    wxID_OSX_MENU_FIRST,
    wxID_OSX_HIDE,
    wxID_OSX_HIDEOTHERS,
    wxID_OSX_SHOWALL,
    wxID_OSX_MENU_LAST,
    wxID_FILEDLGG,
    wxID_FILECTRL,
    wxID_HIGHEST,
    wxMENU_TEAROFF,
    wxMB_DOCKABLE,
    wxNO_FULL_REPAINT_ON_RESIZE,
    wxFULL_REPAINT_ON_RESIZE,
    wxLI_HORIZONTAL,
    wxLI_VERTICAL,
    wxWS_EX_VALIDATE_RECURSIVELY,
    wxWS_EX_BLOCK_EVENTS,
    wxWS_EX_TRANSIENT,
    wxWS_EX_THEMED_BACKGROUND,
    wxWS_EX_PROCESS_IDLE,
    wxWS_EX_PROCESS_UI_UPDATES,
};

// _defs.i
enum wxGeometryCentre {
    wxCENTRE                  = 0x0001,
    wxCENTER                  = wxCENTRE
};

// _defs.i
enum wxOrientation {
    wxHORIZONTAL,
    wxVERTICAL,
    wxBOTH,
    wxORIENTATION_MASK
};

// _defs.i
enum wxDirection {
    wxLEFT,
    wxRIGHT,
    wxUP,
    wxDOWN,
    wxTOP,
    wxBOTTOM,
    wxNORTH,
    wxSOUTH,
    wxWEST,
    wxEAST,
    wxALL,
    wxDIRECTION_MASK
};

// _defs.i
enum wxAlignment {
    wxALIGN_INVALID,
    wxALIGN_NOT,
    wxALIGN_CENTER_HORIZONTAL,
    wxALIGN_CENTRE_HORIZONTAL,
    wxALIGN_LEFT,
    wxALIGN_TOP,
    wxALIGN_RIGHT,
    wxALIGN_BOTTOM,
    wxALIGN_CENTER_VERTICAL,
    wxALIGN_CENTRE_VERTICAL,
    wxALIGN_CENTER,
    wxALIGN_CENTRE,
    wxALIGN_MASK,
};

// _defs.i
enum wxSizerFlagBits {
    wxFIXED_MINSIZE                = 0x8000,
    wxRESERVE_SPACE_EVEN_IF_HIDDEN = 0x0002,
    wxSIZER_FLAG_BITS_MASK         = 0x8002
};

// _defs.i
enum wxStretch {
    wxSTRETCH_NOT,
    wxSHRINK,
    wxGROW,
    wxEXPAND,
    wxSHAPED,
    wxTILE,
    wxSTRETCH_MASK
};

// _defs.i
enum wxBorder {
    wxBORDER_DEFAULT,
    wxBORDER_NONE,
    wxBORDER_STATIC,
    wxBORDER_SIMPLE,
    wxBORDER_RAISED,
    wxBORDER_SUNKEN,
    wxBORDER_DOUBLE,
    wxBORDER_THEME,
    wxBORDER_MASK,
};

// _defs.i
enum wxBackgroundStyle {
    wxBG_STYLE_ERASE,
    wxBG_STYLE_SYSTEM,
    wxBG_STYLE_PAINT,
    wxBG_STYLE_TRANSPARENT,
    wxBG_STYLE_COLOUR,
    wxBG_STYLE_CUSTOM,
};

// _defs.i
enum {
    wxDEFAULT ,
    wxDECORATIVE,
    wxROMAN,
    wxSCRIPT,
    wxSWISS,
    wxMODERN,
    wxTELETYPE,
    wxVARIABLE,
    wxFIXED,
    wxNORMAL,
    wxLIGHT,
    wxBOLD,
    wxITALIC,
    wxSLANT,
    wxSOLID,
    wxDOT,
    wxLONG_DASH,
    wxSHORT_DASH,
    wxDOT_DASH,
    wxUSER_DASH,
    wxTRANSPARENT,
    wxSTIPPLE,
    wxSTIPPLE_MASK,
    wxSTIPPLE_MASK_OPAQUE,
    wxBDIAGONAL_HATCH,
    wxCROSSDIAG_HATCH,
    wxFDIAGONAL_HATCH,
    wxCROSS_HATCH,
    wxHORIZONTAL_HATCH,
    wxVERTICAL_HATCH,
};

// _defs.i
enum wxKeyCode {
};

// _defs.i
enum wxPrintOrientation {
    wxPORTRAIT = 1,
    wxLANDSCAPE
};

// _defs.i
enum wxItemKind {
    wxITEM_SEPARATOR,
    wxITEM_NORMAL,
    wxITEM_CHECK,
    wxITEM_RADIO,
    wxITEM_DROPDOWN,
    wxITEM_MAX
};

// _defs.i
enum wxCheckBoxState {
    wxCHK_UNCHECKED,
    wxCHK_CHECKED,
    wxCHK_UNDETERMINED 
};

// _defs.i
enum wxHitTest {
    wxHT_NOWHERE,
    wxHT_SCROLLBAR_FIRST = wxHT_NOWHERE,
    wxHT_SCROLLBAR_ARROW_LINE_1,    // left or upper arrow to scroll by line
    wxHT_SCROLLBAR_ARROW_LINE_2,    // right or down
    wxHT_SCROLLBAR_ARROW_PAGE_1,    // left or upper arrow to scroll by page
    wxHT_SCROLLBAR_ARROW_PAGE_2,    // right or down
    wxHT_SCROLLBAR_THUMB,           // on the thumb
    wxHT_SCROLLBAR_BAR_1,           // bar to the left/above the thumb
    wxHT_SCROLLBAR_BAR_2,           // bar to the right/below the thumb
    wxHT_SCROLLBAR_LAST,
    wxHT_WINDOW_OUTSIDE,            // not in this window at all
    wxHT_WINDOW_INSIDE,             // in the client area
    wxHT_WINDOW_VERT_SCROLLBAR,     // on the vertical scrollbar
    wxHT_WINDOW_HORZ_SCROLLBAR,     // on the horizontal scrollbar
    wxHT_WINDOW_CORNER,             // on the corner between 2 scrollbars
    wxHT_MAX
};

// _defs.i
enum wxKeyModifier {
    wxMOD_NONE,
    wxMOD_ALT,
    wxMOD_CONTROL,
    wxMOD_ALTGR,
    wxMOD_SHIFT,
    wxMOD_META,
    wxMOD_WIN,
    wxMOD_RAW_CONTROL,
    wxMOD_CMD,
    wxMOD_ALL
};

// _defs.i
enum wxUpdateUI {
    wxUPDATE_UI_NONE          = 0x0000,
    wxUPDATE_UI_RECURSE       = 0x0001,
    wxUPDATE_UI_FROMIDLE      = 0x0002 // Invoked from On(Internal)Idle
};

// _defs.i
enum wxLayoutDirection {
    wxLayout_Default,
    wxLayout_LeftToRight,
    wxLayout_RightToLeft
};

// _event.i
enum wxEventPropagation {
    wxEVENT_PROPAGATE_NONE = 0,
    wxEVENT_PROPAGATE_MAX//  = INT_MAX
};

// _event.i
enum wxEventCategory {
};

// _event.i
enum wxMouseWheelAxis {
    wxMOUSE_WHEEL_VERTICAL,
    wxMOUSE_WHEEL_HORIZONTAL
};

// _event.i
enum wxKeyCategoryFlags {
};

// _event.i
enum wxUpdateUIMode {
    wxUPDATE_UI_PROCESS_ALL,
    wxUPDATE_UI_PROCESS_SPECIFIED
};

// _event.i
enum wxNavigationKeyEventFlags {
};

// _event.i
enum wxIdleMode {
    wxIDLE_PROCESS_ALL,
    wxIDLE_PROCESS_SPECIFIED
};

// _font.i
enum wxFontFamily {
    wxFONTFAMILY_DEFAULT = wxDEFAULT,
    wxFONTFAMILY_DECORATIVE = wxDECORATIVE,
    wxFONTFAMILY_ROMAN = wxROMAN,
    wxFONTFAMILY_SCRIPT = wxSCRIPT,
    wxFONTFAMILY_SWISS = wxSWISS,
    wxFONTFAMILY_MODERN = wxMODERN,
    wxFONTFAMILY_TELETYPE = wxTELETYPE,
    wxFONTFAMILY_MAX,
    wxFONTFAMILY_UNKNOWN = wxFONTFAMILY_MAX
};

// _font.i
enum wxFontStyle {
    wxFONTSTYLE_NORMAL = wxNORMAL,
    wxFONTSTYLE_ITALIC = wxITALIC,
    wxFONTSTYLE_SLANT = wxSLANT,
    wxFONTSTYLE_MAX
};

// _font.i
enum wxFontWeight {
    wxFONTWEIGHT_NORMAL = wxNORMAL,
    wxFONTWEIGHT_LIGHT = wxLIGHT,
    wxFONTWEIGHT_BOLD = wxBOLD,
    wxFONTWEIGHT_MAX
};

// _font.i
enum wxFontSymbolicSize {
    wxFONTSIZE_XX_SMALL = -3,
    wxFONTSIZE_X_SMALL,
    wxFONTSIZE_SMALL,
    wxFONTSIZE_MEDIUM,
    wxFONTSIZE_LARGE,
    wxFONTSIZE_X_LARGE,
    wxFONTSIZE_XX_LARGE
};

// _font.i
enum wxFontFlag {
    wxFONTFLAG_DEFAULT,
    wxFONTFLAG_ITALIC,
    wxFONTFLAG_SLANT,
    wxFONTFLAG_LIGHT,
    wxFONTFLAG_BOLD,
    wxFONTFLAG_ANTIALIASED,
    wxFONTFLAG_NOT_ANTIALIASED,
    wxFONTFLAG_UNDERLINED,
    wxFONTFLAG_STRIKETHROUGH,
    wxFONTFLAG_MASK
};

// _font.i
enum wxFontEncoding {
    wxFONTENCODING_SYSTEM = -1,     // system default
    wxFONTENCODING_DEFAULT,         // current default encoding
    wxFONTENCODING_ISO8859_1,       // West European (Latin1)
    wxFONTENCODING_ISO8859_2,       // Central and East European (Latin2)
    wxFONTENCODING_ISO8859_3,       // Esperanto (Latin3)
    wxFONTENCODING_ISO8859_4,       // Baltic (old) (Latin4)
    wxFONTENCODING_ISO8859_5,       // Cyrillic
    wxFONTENCODING_ISO8859_6,       // Arabic
    wxFONTENCODING_ISO8859_7,       // Greek
    wxFONTENCODING_ISO8859_8,       // Hebrew
    wxFONTENCODING_ISO8859_9,       // Turkish (Latin5)
    wxFONTENCODING_ISO8859_10,      // Variation of Latin4 (Latin6)
    wxFONTENCODING_ISO8859_11,      // Thai
    wxFONTENCODING_ISO8859_12,      // doesn't exist currently, but put it
    wxFONTENCODING_ISO8859_13,      // Baltic (Latin7)
    wxFONTENCODING_ISO8859_14,      // Latin8
    wxFONTENCODING_ISO8859_15,      // Latin9 (a.k.a. Latin0, includes euro)
    wxFONTENCODING_ISO8859_MAX,
    wxFONTENCODING_KOI8,            // KOI8 Russian
    wxFONTENCODING_KOI8_U,          // KOI8 Ukrainian
    wxFONTENCODING_ALTERNATIVE,     // same as MS-DOS CP866
    wxFONTENCODING_BULGARIAN,       // used under Linux in Bulgaria
    wxFONTENCODING_CP437,           // original MS-DOS codepage
    wxFONTENCODING_CP850,           // CP437 merged with Latin1
    wxFONTENCODING_CP852,           // CP437 merged with Latin2
    wxFONTENCODING_CP855,           // another cyrillic encoding
    wxFONTENCODING_CP866,           // and another one
    wxFONTENCODING_CP874,           // WinThai
    wxFONTENCODING_CP932,           // Japanese (shift-JIS)
    wxFONTENCODING_CP936,           // Chinese simplified (GB)
    wxFONTENCODING_CP949,           // Korean (Hangul charset)
    wxFONTENCODING_CP950,           // Chinese (traditional - Big5)
    wxFONTENCODING_CP1250,          // WinLatin2
    wxFONTENCODING_CP1251,          // WinCyrillic
    wxFONTENCODING_CP1252,          // WinLatin1
    wxFONTENCODING_CP1253,          // WinGreek (8859-7)
    wxFONTENCODING_CP1254,          // WinTurkish
    wxFONTENCODING_CP1255,          // WinHebrew
    wxFONTENCODING_CP1256,          // WinArabic
    wxFONTENCODING_CP1257,          // WinBaltic (same as Latin 7)
    wxFONTENCODING_CP12_MAX,
    wxFONTENCODING_UTF7,            // UTF-7 Unicode encoding
    wxFONTENCODING_UTF8,            // UTF-8 Unicode encoding
    wxFONTENCODING_EUC_JP,          // Extended Unix Codepage for Japanese
    wxFONTENCODING_UTF16BE,         // UTF-16 Big Endian Unicode encoding
    wxFONTENCODING_UTF16LE,         // UTF-16 Little Endian Unicode encoding
    wxFONTENCODING_UTF32BE,         // UTF-32 Big Endian Unicode encoding
    wxFONTENCODING_UTF32LE,         // UTF-32 Little Endian Unicode encoding
    wxFONTENCODING_MACROMAN,        // the standard mac encodings
    wxFONTENCODING_MACJAPANESE,
    wxFONTENCODING_MACCHINESETRAD,
    wxFONTENCODING_MACKOREAN,
    wxFONTENCODING_MACARABIC,
    wxFONTENCODING_MACHEBREW,
    wxFONTENCODING_MACGREEK,
    wxFONTENCODING_MACCYRILLIC,
    wxFONTENCODING_MACDEVANAGARI,
    wxFONTENCODING_MACGURMUKHI,
    wxFONTENCODING_MACGUJARATI,
    wxFONTENCODING_MACORIYA,
    wxFONTENCODING_MACBENGALI,
    wxFONTENCODING_MACTAMIL,
    wxFONTENCODING_MACTELUGU,
    wxFONTENCODING_MACKANNADA,
    wxFONTENCODING_MACMALAJALAM,
    wxFONTENCODING_MACSINHALESE,
    wxFONTENCODING_MACBURMESE,
    wxFONTENCODING_MACKHMER,
    wxFONTENCODING_MACTHAI,
    wxFONTENCODING_MACLAOTIAN,
    wxFONTENCODING_MACGEORGIAN,
    wxFONTENCODING_MACARMENIAN,
    wxFONTENCODING_MACCHINESESIMP,
    wxFONTENCODING_MACTIBETAN,
    wxFONTENCODING_MACMONGOLIAN,
    wxFONTENCODING_MACETHIOPIC,
    wxFONTENCODING_MACCENTRALEUR,
    wxFONTENCODING_MACVIATNAMESE,
    wxFONTENCODING_MACARABICEXT,
    wxFONTENCODING_MACSYMBOL,
    wxFONTENCODING_MACDINGBATS,
    wxFONTENCODING_MACTURKISH,
    wxFONTENCODING_MACCROATIAN,
    wxFONTENCODING_MACICELANDIC,
    wxFONTENCODING_MACROMANIAN,
    wxFONTENCODING_MACCELTIC,
    wxFONTENCODING_MACGAELIC,
    wxFONTENCODING_MACKEYBOARD,
    wxFONTENCODING_ISO2022_JP,
    wxFONTENCODING_MACMIN = wxFONTENCODING_MACROMAN ,
    wxFONTENCODING_MACMAX = wxFONTENCODING_MACKEYBOARD ,
    wxFONTENCODING_MAX,             // highest enumerated encoding value
    wxFONTENCODING_UTF16,  // native UTF-16
    wxFONTENCODING_UTF32,  // native UTF-32
    wxFONTENCODING_UNICODE = wxFONTENCODING_UTF16,
    wxFONTENCODING_GB2312 = wxFONTENCODING_CP936, // Simplified Chinese
    wxFONTENCODING_BIG5 = wxFONTENCODING_CP950,   // Traditional Chinese
    wxFONTENCODING_SHIFT_JIS = wxFONTENCODING_CP932, // Shift JIS
    wxFONTENCODING_EUC_KR = wxFONTENCODING_CP949
};

// _functions.i
enum wxStockLabelQueryFlag {
    wxSTOCK_NOFLAGS,
    wxSTOCK_WITH_MNEMONIC,
    wxSTOCK_WITH_ACCELERATOR,
    wxSTOCK_WITHOUT_ELLIPSIS,
    wxSTOCK_FOR_BUTTON,
};

// _functions.i
enum wxStockHelpStringClient {
    wxSTOCK_MENU        // help string to use for menu items
};

// _functions.i
enum wxShutdownFlags {
    wxSHUTDOWN_FORCE    = 1,// can be combined with other flags (MSW-only)
    wxSHUTDOWN_POWEROFF = 2,// power off the computer
    wxSHUTDOWN_REBOOT   = 4,// shutdown and reboot
    wxSHUTDOWN_LOGOFF   = 8 // close session (currently MSW-only)
};

// _functions.i
enum {
    wxBROWSER_NEW_WINDOW,
    wxBROWSER_NOBUSYCURSOR
};

// _gdicmn.i
enum wxBitmapType {
    wxBITMAP_TYPE_INVALID,          // should be == 0 for compatibility!
    wxBITMAP_TYPE_BMP,
    wxBITMAP_TYPE_ICO,
    wxBITMAP_TYPE_CUR,
    wxBITMAP_TYPE_XBM,
    wxBITMAP_TYPE_XBM_DATA,
    wxBITMAP_TYPE_XPM,
    wxBITMAP_TYPE_XPM_DATA,
    wxBITMAP_TYPE_TIF,
    wxBITMAP_TYPE_TIFF,
    wxBITMAP_TYPE_GIF,
    wxBITMAP_TYPE_PNG,
    wxBITMAP_TYPE_JPEG,
    wxBITMAP_TYPE_PNM,
    wxBITMAP_TYPE_PCX,
    wxBITMAP_TYPE_PICT,
    wxBITMAP_TYPE_ICON,
    wxBITMAP_TYPE_ANI,
    wxBITMAP_TYPE_IFF,
    wxBITMAP_TYPE_TGA,
    wxBITMAP_TYPE_MACCURSOR,
    wxBITMAP_TYPE_MAX,
    wxBITMAP_TYPE_ANY,
    wxBITMAP_DEFAULT_TYPE
};

// _gdicmn.i
enum wxPolygonFillMode {
    wxODDEVEN_RULE,
    wxWINDING_RULE
};

// _gdicmn.i
enum wxStockCursor {
    wxCURSOR_NONE,          // should be 0
    wxCURSOR_ARROW,
    wxCURSOR_RIGHT_ARROW,
    wxCURSOR_BULLSEYE,
    wxCURSOR_CHAR,
    wxCURSOR_CROSS,
    wxCURSOR_HAND,
    wxCURSOR_IBEAM,
    wxCURSOR_LEFT_BUTTON,
    wxCURSOR_MAGNIFIER,
    wxCURSOR_MIDDLE_BUTTON,
    wxCURSOR_NO_ENTRY,
    wxCURSOR_PAINT_BRUSH,
    wxCURSOR_PENCIL,
    wxCURSOR_POINT_LEFT,
    wxCURSOR_POINT_RIGHT,
    wxCURSOR_QUESTION_ARROW,
    wxCURSOR_RIGHT_BUTTON,
    wxCURSOR_SIZENESW,
    wxCURSOR_SIZENS,
    wxCURSOR_SIZENWSE,
    wxCURSOR_SIZEWE,
    wxCURSOR_SIZING,
    wxCURSOR_SPRAYCAN,
    wxCURSOR_WAIT,
    wxCURSOR_WATCH,
    wxCURSOR_BLANK,
    wxCURSOR_DEFAULT, // standard X11 cursor
    // wxCURSOR_COPY_ARROW , // MacOS Theme Plus arrow
    wxCURSOR_ARROWWAIT,
    wxCURSOR_OPEN_HAND,
    wxCURSOR_CLOSED_HAND,
    wxCURSOR_MAX
};

// _gdicmn.i
enum wxOutCode {
    wxInside = 0x00 ,
    wxOutLeft = 0x01 ,
    wxOutRight = 0x02 ,
    wxOutTop = 0x08 ,
    wxOutBottom = 0x04
};

// _graphics.i
/* enum wxAntialiasMode {
    wxANTIALIAS_NONE, // should be 0
    wxANTIALIAS_DEFAULT,
}; */

// _graphics.i
/* enum wxInterpolationQuality {
    wxINTERPOLATION_DEFAULT,
    wxINTERPOLATION_NONE,
    wxINTERPOLATION_FAST,
    wxINTERPOLATION_GOOD,
    wxINTERPOLATION_BEST
}; */

// _graphics.i
/* enum wxCompositionMode {
    wxCOMPOSITION_INVALID,
    wxCOMPOSITION_CLEAR, 
    wxCOMPOSITION_SOURCE, 
    wxCOMPOSITION_OVER, 
    wxCOMPOSITION_IN, 
    wxCOMPOSITION_OUT, 
    wxCOMPOSITION_ATOP, 
    wxCOMPOSITION_DEST, 
    wxCOMPOSITION_DEST_OVER, 
    wxCOMPOSITION_DEST_IN, 
    wxCOMPOSITION_DEST_OUT, 
    wxCOMPOSITION_DEST_ATOP, 
    wxCOMPOSITION_XOR, 
    wxCOMPOSITION_ADD, 
}; */

// _graphics.i
/* enum wxAntialiasMode {
    wxANTIALIAS_NONE, // should be 0
    wxANTIALIAS_DEFAULT,
}; */

// _graphics.i
/* enum wxInterpolationQuality {
    wxINTERPOLATION_DEFAULT,
    wxINTERPOLATION_NONE,
    wxINTERPOLATION_FAST,
    wxINTERPOLATION_GOOD,
    wxINTERPOLATION_BEST
}; */

// _graphics.i
/* enum wxCompositionMode {
    wxCOMPOSITION_INVALID,
    wxCOMPOSITION_CLEAR, 
    wxCOMPOSITION_SOURCE, 
    wxCOMPOSITION_OVER, 
    wxCOMPOSITION_IN, 
    wxCOMPOSITION_OUT, 
    wxCOMPOSITION_ATOP, 
    wxCOMPOSITION_DEST, 
    wxCOMPOSITION_DEST_OVER, 
    wxCOMPOSITION_DEST_IN, 
    wxCOMPOSITION_DEST_OUT, 
    wxCOMPOSITION_DEST_ATOP, 
    wxCOMPOSITION_XOR, 
    wxCOMPOSITION_ADD, 
}; */

// _icon.i
enum {
};

// _image.i
enum {
    wxIMAGE_ALPHA_TRANSPARENT,
    wxIMAGE_ALPHA_THRESHOLD,
    wxIMAGE_ALPHA_OPAQUE
};

// _image.i
enum wxImageResizeQuality {
    wxIMAGE_QUALITY_NEAREST,
    wxIMAGE_QUALITY_BILINEAR,
    wxIMAGE_QUALITY_BICUBIC,
    wxIMAGE_QUALITY_BOX_AVERAGE,
    wxIMAGE_QUALITY_NORMAL,
    wxIMAGE_QUALITY_HIGH,
};

// _image.i
enum wxImageResolution {
    wxIMAGE_RESOLUTION_NONE = 0,
    wxIMAGE_RESOLUTION_INCHES = 1,
    wxIMAGE_RESOLUTION_CM = 2
};

// _image.i
enum {
    wxPNG_TYPE_COLOUR = 0,
    wxPNG_TYPE_GREY = 2,
    wxPNG_TYPE_GREY_RED = 3
};

// _image.i
enum {
    wxBMP_24BPP        = 24, // default, do not need to set
    wxBMP_8BPP         =  8, // 8bpp, quantized colors
    wxBMP_8BPP_GREY    =  9, // 8bpp, rgb averaged to greys
    wxBMP_8BPP_GRAY    =  wxBMP_8BPP_GREY,
    wxBMP_8BPP_RED     = 10, // 8bpp, red used as greyscale
    wxBMP_8BPP_PALETTE = 11, // 8bpp, use the wxImage's palette
    wxBMP_4BPP         =  4, // 4bpp, quantized colors
    wxBMP_1BPP         =  1, // 1bpp, quantized "colors"
    wxBMP_1BPP_BW      =  2  // 1bpp, black & white from red
};

// _image.i
enum {
    // wxQUANTIZE_INCLUDE_WINDOWS_COLOURS,
    // wxQUANTIZE_FILL_DESTINATION_IMAGE
};

// _imaglist.i
enum {
    wxIMAGELIST_DRAW_NORMAL ,
    wxIMAGELIST_DRAW_TRANSPARENT,
    wxIMAGELIST_DRAW_SELECTED,
    wxIMAGELIST_DRAW_FOCUSED,
    wxIMAGE_LIST_NORMAL,
    wxIMAGE_LIST_SMALL,
    wxIMAGE_LIST_STATE
};

// _listctrl.i
enum {
    wxLC_VRULES,
    wxLC_HRULES,
    wxLC_ICON,
    wxLC_SMALL_ICON,
    wxLC_LIST,
    wxLC_REPORT,
    wxLC_ALIGN_TOP,
    wxLC_ALIGN_LEFT,
    wxLC_AUTOARRANGE,
    wxLC_VIRTUAL,
    wxLC_EDIT_LABELS,
    wxLC_NO_HEADER,
    wxLC_NO_SORT_HEADER,
    wxLC_SINGLE_SEL,
    wxLC_SORT_ASCENDING,
    wxLC_SORT_DESCENDING,
    wxLC_MASK_TYPE,
    wxLC_MASK_ALIGN,
    wxLC_MASK_SORT
};

// _listctrl.i
enum {
    wxLIST_MASK_STATE,
    wxLIST_MASK_TEXT,
    wxLIST_MASK_IMAGE,
    wxLIST_MASK_DATA,
    wxLIST_SET_ITEM,
    wxLIST_MASK_WIDTH,
    wxLIST_MASK_FORMAT,
    wxLIST_STATE_DONTCARE,
    wxLIST_STATE_DROPHILITED,
    wxLIST_STATE_FOCUSED,
    wxLIST_STATE_SELECTED,
    wxLIST_STATE_CUT,
    wxLIST_STATE_DISABLED,
    wxLIST_STATE_FILTERED,
    wxLIST_STATE_INUSE,
    wxLIST_STATE_PICKED,
    wxLIST_STATE_SOURCE,
    wxLIST_HITTEST_ABOVE,
    wxLIST_HITTEST_BELOW,
    wxLIST_HITTEST_NOWHERE,
    wxLIST_HITTEST_ONITEMICON,
    wxLIST_HITTEST_ONITEMLABEL,
    wxLIST_HITTEST_ONITEMRIGHT,
    wxLIST_HITTEST_ONITEMSTATEICON,
    wxLIST_HITTEST_TOLEFT,
    wxLIST_HITTEST_TORIGHT,
    wxLIST_HITTEST_ONITEM,
    wxLIST_GETSUBITEMRECT_WHOLEITEM,
};

// _listctrl.i
enum {
    wxLIST_NEXT_ABOVE,          // Searches for an item above the specified item
    wxLIST_NEXT_ALL,            // Searches for subsequent item by index
    wxLIST_NEXT_BELOW,          // Searches for an item below the specified item
    wxLIST_NEXT_LEFT,           // Searches for an item to the left of the specified item
    wxLIST_NEXT_RIGHT           // Searches for an item to the right of the specified item
};

// _listctrl.i
enum {
    wxLIST_ALIGN_DEFAULT,
    wxLIST_ALIGN_LEFT,
    wxLIST_ALIGN_TOP,
    wxLIST_ALIGN_SNAP_TO_GRID
};

// _listctrl.i
enum wxListColumnFormat {
    wxLIST_FORMAT_LEFT,
    wxLIST_FORMAT_RIGHT,
    wxLIST_FORMAT_CENTRE,
    wxLIST_FORMAT_CENTER = wxLIST_FORMAT_CENTRE
};

// _listctrl.i
enum {
    wxLIST_AUTOSIZE = -1,
    wxLIST_AUTOSIZE_USEHEADER = -2      // partly supported by generic version
};

// _listctrl.i
enum {
    wxLIST_RECT_BOUNDS,
    wxLIST_RECT_ICON,
    wxLIST_RECT_LABEL
};

// _listctrl.i
enum {
    wxLIST_FIND_UP,
    wxLIST_FIND_DOWN,
    wxLIST_FIND_LEFT,
    wxLIST_FIND_RIGHT
};

// _mousestate.i
enum wxMouseButton {
    wxMOUSE_BTN_ANY,
    wxMOUSE_BTN_NONE,
    wxMOUSE_BTN_LEFT,
    wxMOUSE_BTN_MIDDLE,
    wxMOUSE_BTN_RIGHT,
    wxMOUSE_BTN_AUX1,
    wxMOUSE_BTN_AUX2,
    wxMOUSE_BTN_MAX
};

// _notebook.i
enum {
    // wxNB_FIXEDWIDTH,
    // wxNB_TOP,
    // wxNB_LEFT,
    // wxNB_RIGHT,
    // wxNB_BOTTOM,
    // wxNB_MULTILINE,
    // wxNB_NOPAGETHEME,
    // wxNB_HITTEST_NOWHERE,
    // wxNB_HITTEST_ONICON,
    // wxNB_HITTEST_ONLABEL,
    // wxNB_HITTEST_ONITEM,
    // wxNB_HITTEST_ONPAGE,
};

// _notebook.i
enum {
    // wxLB_DEFAULT = 0,
    // wxLB_TOP    = 0x1,
    // wxLB_BOTTOM = 0x2,
    // wxLB_LEFT   = 0x4,
    // wxLB_RIGHT  = 0x8,
    // wxLB_ALIGN_MASK = 0xf,
};

// _notebook.i
enum {
    // wxCHB_DEFAULT,
    // wxCHB_TOP,
    // wxCHB_BOTTOM,
    // wxCHB_LEFT,
    // wxCHB_RIGHT,
    // wxCHB_ALIGN_MASK
};

// _pen.i
enum wxPenStyle {
    wxPENSTYLE_INVALID,
    wxPENSTYLE_SOLID,
    wxPENSTYLE_DOT,
    wxPENSTYLE_LONG_DASH,
    wxPENSTYLE_SHORT_DASH,
    wxPENSTYLE_DOT_DASH,
    wxPENSTYLE_USER_DASH,
    wxPENSTYLE_TRANSPARENT,
    wxPENSTYLE_STIPPLE_MASK_OPAQUE,
    wxPENSTYLE_STIPPLE_MASK,
    wxPENSTYLE_STIPPLE,
    wxPENSTYLE_BDIAGONAL_HATCH,
    wxPENSTYLE_CROSSDIAG_HATCH,
    wxPENSTYLE_FDIAGONAL_HATCH,
    wxPENSTYLE_CROSS_HATCH,
    wxPENSTYLE_HORIZONTAL_HATCH,
    wxPENSTYLE_VERTICAL_HATCH,
    wxPENSTYLE_FIRST_HATCH,
    wxPENSTYLE_LAST_HATCH,
};

// _pen.i
enum wxPenJoin {
    wxJOIN_INVALID,
    wxJOIN_BEVEL,
    wxJOIN_MITER,
    wxJOIN_ROUND,
};

// _pen.i
enum wxPenCap {
    wxCAP_INVALID,
    wxCAP_ROUND,
    wxCAP_PROJECTING,
    wxCAP_BUTT
};

// _process.i
enum {
    wxPROCESS_DEFAULT = 0,
    wxPROCESS_REDIRECT = 1
};

// _process.i
enum wxKillError {
    wxKILL_OK,              // no error
    wxKILL_BAD_SIGNAL,      // no such signal
    wxKILL_ACCESS_DENIED,   // permission denied
    wxKILL_NO_PROCESS,      // no such process
    wxKILL_ERROR            // another, unspecified error
};

// _process.i
enum wxKillFlags {
    wxKILL_NOCHILDREN = 0,  // don't kill children
    wxKILL_CHILDREN = 1     // kill children
};

// _process.i
enum wxSignal {
    wxSIGNONE = 0,  // verify if the process exists under Unix
    wxSIGHUP,
    wxSIGINT,
    wxSIGQUIT,
    wxSIGILL,
    wxSIGTRAP,
    wxSIGABRT,
    wxSIGIOT = wxSIGABRT,   // another name
    wxSIGEMT,
    wxSIGFPE,
    wxSIGKILL,
    wxSIGBUS,
    wxSIGSEGV,
    wxSIGSYS,
    wxSIGPIPE,
    wxSIGALRM,
    wxSIGTERM
};

// _process.i
enum {
    wxEXEC_ASYNC    = 0,
    wxEXEC_SYNC     = 1,
    wxEXEC_NOHIDE   = 2,
    wxEXEC_MAKE_GROUP_LEADER = 4,
    wxEXEC_NODISABLE = 8,
    wxEXEC_NOEVENTS = 16,
    wxEXEC_BLOCK = wxEXEC_SYNC | wxEXEC_NOEVENTS,
    wxEXEC_SHOW_CONSOLE,
    wxEXEC_HIDE_CONSOLE
};

// _region.i
enum wxRegionContain {
    wxOutRegion = 0,
    wxPartRegion = 1,
    wxInRegion = 2
};

#endif

