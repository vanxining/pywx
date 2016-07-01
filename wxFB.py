
import sys
import re

if len(sys.argv) == 1:
    print("No input file.")
    exit()

code = open(sys.argv[1]).read()

rep = (
    ('\t', "    "),
    ("import wx.xrc\n", ""),
    ("wx.EmptyString", 'u""'),
    ("SetSizeHintsSz", "SetSizeHints"),
    ("SetToolTipString", "SetToolTip"),
    ("AppendItem", "Append"),
    ("EVT_CLOSE", "EVT_CLOSE_WINDOW"),
    (" (", "("),
    ("( ", "("),
    (" )", ")"),
    ("		\n" * 2, "		\n"),
)

for r in rep:
    code = code.replace(*r)

patterns = (
    (re.compile(r"(\S+)\.Bind\("), r"wx.PyBind(\1, ",),
)

for p in patterns:
    code = p[0].sub(p[1], code)

pos = code.find(' "')  # TODO:
while pos != -1:
    pos += 1
    code = code[:pos] + 'u' + code[pos:]
    pos = code.find(' "', pos + 2)

with open(sys.argv[1], "w") as outf:
    outf.write(code)
