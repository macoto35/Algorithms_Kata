import turtle
from random import randint

t = turtle.Turtle()
w = turtle.Screen()
t.left(90)

def tree(branchLen, branchWidth, t):
    if branchLen > 5:
        t.pensize(branchWidth)
        if branchLen < 15:
            t.pencolor("green")
        else:
            t.pencolor("brown")

        t.down()
        t.forward(branchLen)
        angle = randint(20, 40)
        t.right(angle)
        tree(branchLen - randint(10, 15), branchWidth - 1, t)
        t.left(angle * 2)
        tree(branchLen - randint(10, 15), branchWidth - 1, t)
        
        t.right(angle)
        t.up()
        t.backward(branchLen)

tree(75, 10, t)
w.exitonclick()

