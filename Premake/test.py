# -*- coding: utf-8 -*-

import thread
import sys
import time

import wx

#-------------------------------------------------------------------#


def NewEvent():
    evttype = wx.PyNewEventType(False)

    class _Event(wx.PyEvent):
        def __init__(self, **kw):
            wx.PyEvent.__init__(self)
            self.SetEventType(evttype.GetEventType())
            self.__dict__.update(kw)

    return _Event, evttype



def NewCommandEvent():
    evttype = wx.PyNewEventType(True)

    class _Event(wx.PyCommandEvent):
        def __init__(self, id, **kw):
            wx.PyCommandEvent.__init__(self, evttype, id)
            self.__dict__.update(kw)

    return _Event, evttype

#-------------------------------------------------------------------#


class App(wx.PyApp):
    def __init__(self):
        wx.PyApp.__init__(self)
        self._BootstrapApp()

    def OnInit(self):
        self.win = MyFrame()
        self.win.Show()

        for handler in wx.Image.GetHandlers():
            print(handler.GetClassInfo().GetClassName())

        return True

#-------------------------------------------------------------------#


(WorkerFinishEvent, EVT_WORKER_FIN) = NewEvent()


class Worker:
    def __init__(self, evt_handler):
        self.evt_handler = evt_handler

    def Start(self):
        print("Worker.Start()")
        thread.start_new_thread(self.Run, ())

    def Run(self):
        print("Worker.Run()")
        time.sleep(0.5)

        evt = WorkerFinishEvent()
        evt.hello = "Hello, world!"
        wx.PostEvent(self.evt_handler, evt)

#-------------------------------------------------------------------#


class MyFrame(wx.Frame):
    def __init__(self):
        wx.Frame.__init__(self, None, wx.ID_ANY, u"开始", size=wx.DefaultSize)

        usable = wx.GetClientDisplayRect()
        w = int(usable.width * 0.5)
        h = int(usable.height * 0.75)
        self.SetSize(w, h)
        self.Centre(wx.BOTH)

        self.SetIcon(wx.Icon(u"res/drawable/Icon.ico", wx.BITMAP_TYPE_ICO))
        self.bmp = wx.Bitmap(u"res/drawable/tag.bmp", wx.BITMAP_TYPE_BMP)

        self.Centre(wx.BOTH)

        self.inurl = wx.TextCtrl(self, wx.ID_ANY, pos=wx.Point(90, 190), size=wx.Size(290, -1))
        self.outurl = wx.TextCtrl(self, wx.ID_ANY, pos=wx.Point(90, 220), size=wx.Size(290, -1))

        self.begin_btn = wx.Button(self, wx.ID_ANY, u"开始转换(&B)", pos=wx.Point(90, 255))
        self.stop_btn = wx.Button(self, wx.ID_ANY, u"关闭窗口(&S)", pos=wx.Point(90, 285))
        self.thread_btn = wx.Button(self, wx.ID_ANY, u"创建线程(&C)", pos=wx.Point(90, 315))

        wx.PyBind(self, wx.EVT_ICONIZE, self.OnIconize)
        wx.PyBind(self, wx.EVT_PAINT, self.OnPaint)
        wx.PyBind(self, wx.EVT_KEY_UP, self.OnKeyUp)

        wx.PyBind(self.begin_btn, wx.EVT_BUTTON, self.OnBegin)
        wx.PyBind(self.stop_btn, wx.EVT_BUTTON, self.OnStop)
        wx.PyBind(self.thread_btn, wx.EVT_BUTTON, self.OnThread)
        wx.PyBind(self, EVT_WORKER_FIN, self.OnThreadEnded)

        for chd in self.GetChildren():
            size = chd.GetSize()
            print(chd, "[%d, %d]" % (size.x, size.y))

    def OnClose(self, event):
        self.Close()

    def OnMaximize(self, event):
        self.Maximize(not self.IsMaximized())

    def OnShow(self, event):
        pass

    def OnIconize(self, event):
        print("OnIconize():", event)

    def OnPaint(self, event):
        dc = wx.PaintDC(self)

        font = self.GetFont()
        font.SetFaceName(u"黑体")
        font.SetPointSize(18)

        dc.SetFont(font)
        dc.SetTextForeground(wx.WHITE)
        dc.DrawText(u"你好!", 50, 50)

        dc.DrawBitmap(self.bmp, 50, 90)

        mdc = wx.MemoryDC(self.bmp)
        dc.Blit(50, 140, self.bmp.GetWidth(), self.bmp.GetHeight(), mdc, 0, 0)

        extents = []
        if dc.GetPartialTextExtents(u"Hello", extents):
            print(extents)

    def OnKeyUp(self, event):
        print(event.GetKeyCode())

    def OnBegin(self, event):
        print("OnBegin()")

    def OnStop(self, event):
        self.Close()

    def OnThread(self, event):
        print("OnThread()")
        worker = Worker(self)
        worker.Start()

    def OnThreadEnded(self, event):
        print("OnThreadEnded() -- [%s]" % event.hello)

#-------------------------------------------------------------------#


if __name__ == "__main__":
    app = App()
    app.MainLoop()
