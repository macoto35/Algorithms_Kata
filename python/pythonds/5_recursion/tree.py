import turtle
from random import randint

t = turtle.Turtle()
w = turtle.Screen()

def tree(branchLen, branchWidth, t):
    if branchLen > 5:
        t.pensize(branchWidth)
        if branchLen < 15:
            t.pencolor("green")
        else:
            t.pencolor("brown")

        t.forward(branchLen)
        t.right(20)
        tree(branchLen - randint(10, 15), branchWidth - 1, t)
        t.left(40)
        tree(branchLen - randint(10, 15), branchWidth - 1, t)
        
        t.right(20)
        t.backward(branchLen)

tree(75, 10, t)
w.exitonclick()
