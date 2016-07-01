
# raw_input("DEBUGGING...")

import wx
print wx
print wx.NullIconBundle

print "WXK_TAB:", wx.WXK_TAB
print ""

print "Test wxUIntToPtr():"
print wx.UIntToPtr(0)
print wx.UIntToPtr(100)
print ""

first = wx.ClassInfo.GetFirst()
print "First class in the chain:", first.GetClassName()

cls = first
while cls:
    print "%s[%d bytes]" % (cls.GetClassName(), cls.GetSize())
    cls = cls.GetNext()

print ""

ci = wx.ClassInfo(u"X", None, None, 12, None)
print "GetBaseClassName1():", ci.GetBaseClassName1()
print "GetClassName():", ci.GetClassName()
print ""

rc = wx.Rect(10, 10, 50, 50)
print rc.x, rc.y, rc.width, rc.height

rc.height += 100
print rc.x, rc.y, rc.width, rc.height