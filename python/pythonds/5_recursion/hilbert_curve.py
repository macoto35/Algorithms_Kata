import turtle
from enum import Enum

class Direction(Enum):
    LEFT = 1
    RIGHT = 2
    UP = 3
    DOWN = 4

#https://www.compuphase.com/hilbert.htm
def hilbertCurve(t, llx, lly, urx, ury, level, length, direction = Direction.UP):
    print('----' * level, llx, lly, urx, ury, level, length, direction)

    midx = (llx + urx) / 2
    midy = (lly + ury) / 2

    if level == 1:
        if direction == Direction.LEFT:
            t.penup()
            t.goto((llx + midx) / 2, (ury + midy) / 2)
            print('LEFT', (llx + midx) / 2, (ury + midy) / 2)
            t.pendown()
            # right
            t.forward(length)
            # down
            t.right(90)
            t.forward(length)
            # left
            t.right(90)
            t.forward(length)
        elif direction == Direction.RIGHT:
            t.penup()
            t.goto((urx + midx) / 2, (lly + midy) / 2)
            print('RIGHT', (urx + midx) / 2, (lly + midy) / 2)
            t.pendown()
            # left
            t.backward(length)
            # up
            t.left(90)
            t.forward(length)
            # right
            t.right(90)
            t.forward(length)
        elif direction == Direction.UP:
            t.penup()
            t.goto((llx + midx) / 2, (ury + midy) / 2)
            print('UP', (llx + midx) / 2, (ury + midy) / 2)
            t.pendown()
            # down
            t.right(90)
            t.forward(length)
            # right
            t.left(90)
            t.forward(length)
            # up
            t.left(90)
            t.forward(length)
        elif direction == Direction.DOWN:
            t.penup()
            t.goto((urx + midx) / 2, (lly + midy) / 2)
            print('DOWN', (urx + midx) / 2, (lly + midy) / 2)
            t.pendown()
            # up
            t.left(90)
            t.forward(length)
            # left
            t.left(90)
            t.forward(length)
            # down
            t.left(90)
            t.forward(length)
    elif level > 1:
        if direction == Direction.LEFT:
            hilbertCurve(t, llx, lly + ury, urx + llx, ury, level - 1, length / 2, Direction.UP) # 2-quadrant
            # right
            t.right(90)
            t.forward(length / 2)
            hilbertCurve(t, llx + urx, lly + ury, urx, ury, level - 1, length / 2, Direction.LEFT) # 1-quadrant
            # down
            t.left(90)
            t.forward(length / 2)
            t.left(90)
            hilbertCurve(t, llx + urx, lly, urx, ury + lly, level - 1, length / 2, Direction.LEFT) # 4-quadrant
            # left
            t.forward(length / 2)
            t.right(180)
            hilbertCurve(t, llx, lly, urx + llx, ury + lly, level - 1, length / 2, Direction.DOWN) # 3-quadrant

        elif direction == Direction.RIGHT:
            hilbertCurve(t, llx + urx, lly, urx, ury + lly, level - 1, length / 2, Direction.DOWN) # 4-quadrant
            # left
            t.right(90)
            t.forward(length / 2)
            t.left(180)
            hilbertCurve(t, llx, lly, urx + llx, ury + lly, level - 1, length / 2, Direction.RIGHT) # 3-quadrant
            # up
            t.left(90)
            t.forward(length / 2)
            t.right(90)
            hilbertCurve(t, llx, lly + ury, urx + llx, ury, level - 1, length / 2, Direction.RIGHT) # 2-quadrant
            # right
            t.forward(length / 2)
            hilbertCurve(t, llx + urx, lly + ury, urx, ury, level - 1, length / 2, Direction.UP) # 1-quadrant

        elif direction == Direction.UP:
            hilbertCurve(t, llx, lly + ury, urx + llx, ury, level - 1, length / 2, Direction.LEFT) # 2-quadrant
            # down
            t.left(90)
            t.forward(length / 2)
            t.left(90)
            hilbertCurve(t, llx, lly, urx + llx, ury + lly, level - 1, length / 2, Direction.UP) # 3-quadrant
            # right
            t.right(90)
            t.forward(length / 2)
            hilbertCurve(t, llx + urx, lly, urx, ury + lly, level - 1, length / 2, Direction.UP) # 4-quadrant
            # up
            t.forward(length / 2)
            t.right(90)
            hilbertCurve(t, llx + urx, lly + ury, urx, ury, level - 1, length / 2, Direction.RIGHT) # 1-quadrant

        elif direction == Direction.DOWN:
            hilbertCurve(t, llx + urx, lly, urx, ury + lly, level - 1, length / 2, Direction.RIGHT) # 4-quadrant
            # up
            t.left(90)
            t.forward(length / 2)
            t.right(90)
            hilbertCurve(t, llx + urx, lly + ury, urx, ury, level - 1, length / 2, Direction.DOWN) # 1-quadrant
            # left
            t.right(90)
            t.forward(length / 2)
            t.left(180)
            hilbertCurve(t, llx, lly + ury, urx + llx, ury, level - 1, length / 2, Direction.DOWN) # 2-quadrant
            # down
            t.forward(length / 2)
            t.left(90)
            hilbertCurve(t, llx, lly, urx + llx, ury + lly, level - 1, length / 2, Direction.LEFT) # 3-quadrant

def main():
    t = turtle.Turtle()
    w = turtle.Screen()
    
    w.setworldcoordinates(-120, -120, 120, 120)
    t.color('red')
    t.penup()
    t.goto(-120, 0)
    t.pendown()
    t.forward(240)
    t.penup()
    t.goto(0, -120)
    t.pendown()
    t.left(90)
    t.forward(240)
    t.right(90)

    t.color('black')
    hilbertCurve(t, -100, -100, 100, 100, 3, 100)
    w.exitonclick()

main()

