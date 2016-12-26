
import os
import re

enum_begin = re.compile(r"enum\s*\{?")
enum = False

enums = []


for f in open("Enums.txt"):
    f = f.strip()
    if f.startswith("// "):
        continue
    
    swigf = os.path.split(f)[-1]
    for line in open(f):
        line = line.strip()
        if not line:
            continue
        
        if enum_begin.match(line):
            enums.append("// " + swigf)
            enums.append(line)
            enum = ";" not in line
        elif enum:
            if line.startswith("wx") and not line.startswith("wxEVT_"):
                enums.append("    " + line)
            elif line.startswith('{'):
                enums[-1] += " {"
            
            if "};" in line:
                enums.append(line)
                enums.append("")
                enum = False


print "#ifdef __CASTXML__\n"
print "\n".join(enums)
print "#endif"
