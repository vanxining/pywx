# -*- coding: utf-8 -*-

import sys
try:
    import thread
except ModuleNotFoundError:
    import _thread as thread
import time
import traceback

import wx


def NewEvent():
    event_type = wx.PyNewEventType(False)

    class _Event(wx.PyEvent):
        def __init__(self, **kwargs):
            wx.PyEvent.__init__(self)
            self.SetEventType(event_type.GetEventType())
            self.__dict__.update(kwargs)

    return _Event, event_type



def NewCommandEvent():
    event_type = wx.PyNewEventType(True)

    class _Event(wx.PyCommandEvent):
        # noinspection PyShadowingBuiltins
        def __init__(self, id, **kwargs):
            wx.PyCommandEvent.__init__(self, event_type, id)
            self.__dict__.update(kwargs)

    return _Event, event_type


class App(wx.PyApp):
    def __init__(self):
        wx.PyApp.__init__(self)
        self._BootstrapApp()

    # noinspection PyMethodMayBeStatic
    def OnInit(self):
        # noinspection PyBroadException
        try:
            win = MyFrame()
            win.Show()

            for handler in wx.Image.GetHandlers():
                print(handler.GetClassInfo().GetClassName())

            return True
        except:
            traceback.print_exc()

            return False



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

        event = WorkerFinishEvent()
        event.hello = "Hello, world!"
        wx.PostEvent(self.evt_handler, event)


DPI_SCALE_FACTOR = 2.0


def S(dimension):
    return int(dimension * DPI_SCALE_FACTOR)


# noinspection PyMethodMayBeStatic
class MyFrame(wx.Frame):
    def __init__(self):
        wx.Frame.__init__(self, None, wx.ID_ANY, u"开始", size=wx.DefaultSize)

        global DPI_SCALE_FACTOR
        DPI_SCALE_FACTOR = self.GetContentScaleFactor()

        self.SetFont(wx.Font(9, 70, 90, 90, False, u"Segoe UI"))

        usable = wx.GetClientDisplayRect()
        w = max(int(usable.width * 0.5), 750)
        h = int(usable.height * 0.75)
        self.SetSize(w, h)
        self.Centre(wx.BOTH)

        self.SetIcon(wx.Icon(u"res/drawable/Icon.ico", wx.BITMAP_TYPE_ICO))
        self.bmp = wx.Bitmap(u"res/drawable/tag.bmp", wx.BITMAP_TYPE_BMP)

        self.inurl = wx.TextCtrl(self, wx.ID_ANY, pos=wx.Point(S(90), S(190)), size=wx.Size(S(290), -1))
        self.outurl = wx.TextCtrl(self, wx.ID_ANY, pos=wx.Point(S(90), S(220)), size=wx.Size(S(290), -1))

        self.begin_btn = wx.Button(self, wx.ID_ANY, u"开始转换(&B)", pos=wx.Point(S(90), S(255)))
        self.stop_btn = wx.Button(self, wx.ID_ANY, u"关闭窗口(&S)", pos=wx.Point(S(90), S(285)))
        self.thread_btn = wx.Button(self, wx.ID_ANY, u"创建线程(&C)", pos=wx.Point(S(90), S(315)))
        self.xrc_btn = wx.Button(self, wx.ID_ANY, u"XRC(&X)", pos=wx.Point(S(90), S(345)))

        self.Bind(wx.EVT_ICONIZE, self.OnIconize)
        self.Bind(wx.EVT_PAINT, self.OnPaint)
        self.Bind(wx.EVT_KEY_UP, self.OnKeyUp)

        self.begin_btn.Bind(wx.EVT_BUTTON, self.OnBegin)
        self.stop_btn.Bind(wx.EVT_BUTTON, self.OnStop)
        self.thread_btn.Bind(wx.EVT_BUTTON, self.OnThread)
        self.Bind(EVT_WORKER_FIN, self.OnThreadEnded)
        self.xrc_btn.Bind(wx.EVT_BUTTON, self.OnXRC)

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
        dc.DrawText(u"你好!", S(50), S(50))

        dc.DrawBitmap(self.bmp, S(50), S(90))

        mdc = wx.MemoryDC(self.bmp)
        dc.Blit(S(50), S(140), self.bmp.GetWidth(), self.bmp.GetHeight(), mdc, 0, 0)

        extents = []
        if dc.GetPartialTextExtents(u"Hello", extents):
            print(extents)

    def OnKeyUp(self, event):
        print(event.GetKeyCode())

    def OnBegin(self, event):
        print("OnBegin()")

        wx.MessageBox(u"成功转换！", u"pywx")

    def OnStop(self, event):
        self.Close()

    def OnThread(self, event):
        print("OnThread()")
        worker = Worker(self)
        worker.Start()

    def OnThreadEnded(self, event):
        print("OnThreadEnded() -- [%s]" % event.hello)

    def OnXRC(self, event):
        res = wx.XmlResource.Get()
        res.InitAllHandlers()

        if res.Load(u"test.xrc"):
            frame = res.LoadFrame(self, u"main_window")
            frame.Show()
        else:
            print("OnXRC(): failed to load resources")


if __name__ == "__main__":
    wx.SetProcessDPIAware()

    app = App()
    app.MainLoop()
