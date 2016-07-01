
import sys
import os


if os.path.exists("pywx.vcxproj.user"):
    user = open("pywx.vcxproj.user").read()
else:
    user = ""

args = []

shared = False
if "static" not in sys.argv:
    shared = True
    args.append("--wx-shared")

pydebug = False
if "pydebug" in sys.argv:
    pydebug = True
    args.append("--pydebug")

print("Arguments: shared=%d, pydebug=%d" % (shared, pydebug))

os.system("premake4 %s vs2012" % " ".join(args))

prj = open("pywx.vcxproj").read()
prj = prj.replace("v110", "v140")

with open("pywx.vcxproj", "w") as outf:
    outf.write(prj)

if user:
    with open("pywx.vcxproj.user", "w") as outf:
        outf.write(user)