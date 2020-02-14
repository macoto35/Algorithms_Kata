from turtle import *

class ProgressAnimation:
    def __init__(self):
        self.screen = Screen()
        self.screen.setworldcoordinates(0, 0, 200, 200)
    
    def enable_exitonclick(self):
        self.screen.exitonclick()
    
    def turtle_init(self, arr):
        size = len(arr)
        tarr = []

        for i in range(size):
            # default settings
            t = Turtle()
            t.shape('square')
            t.shapesize(0.1, 0.1, 0.1)
            t.pensize(5)
            t.speed(0)
        
            # set location and draw
            self._draw(t, i, arr[i])

            tarr.append(t)
    
        return tarr

    def turtle_selection_draw(self, arr, tarr, ci, li, ei):
        for i in range(len(arr)):
            t = tarr[i]

            if i == ci:
                t.color('red') # current idx
            elif i == li:
                t.color('yellow') # current large idx
            elif i == ei:
                t.color('blue') # last index
            else:
                t.color('black')

            self._redraw(t, i, arr[i])

    def turtle_insertion_draw(self, arr, tarr, idx, color):
        for i in range(len(arr)):
            t = tarr[i]

            if i == idx:
                t.color(color)
            else:
                t.color('black')

            self._redraw(t, i, arr[i])
    
    def turtle_draw(self, arr, tarr, idxes):
        for i in range(len(arr)):
            t = tarr[i]

            if i in idxes:
                t.color('red')
            else:
                t.color('black')

            self._redraw(t, i, arr[i])

    def _redraw(self, t, i, item):
        self._clear(t)
        self._draw(t, i, item)

    def _draw(self, t, i, item):
        t.up()
        t.goto(i * 10, 0)
        t.down()
        t.left(90)
        t.goto(i * 10, item)

    def _clear(self, t):
        t.clear()

