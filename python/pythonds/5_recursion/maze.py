import turtle

PART_OF_PATH = 'O'
TRIED = '.'
OBSTACLE = '+'
DEAD_END = '-'

class Maze:
    def __init__(self, mazeFileName):
        self.mazelist = []

        row = 0
        for line in open(mazeFileName, 'r'):
            rowList = []
            column = 0
            for ch in line[:-1]:
                rowList.append(ch)
                if ch == 'S':
                    self.startRow = row
                    self.startCol = column
                column += 1
            row += 1
            self.mazelist.append(rowList)

        self.rowsInMaze = row
        self.columnsInMaze = len(self.mazelist[0])
        self.xTranslate = -self.columnsInMaze / 2
        self.yTranslate = self.rowsInMaze / 2

        self.t = turtle.Turtle()
        self.t.shape('turtle')
        self.w = turtle.Screen()
        self.w.setworldcoordinates(-(self.columnsInMaze - 1) / 2 - .5, -(self.rowsInMaze - 1) / 2 - .5, (self.columnsInMaze - 1) / 2 + .5, (self.rowsInMaze - 1) / 2 + .5)


    def drawMaze(self):
        self.t.speed(10)
        self.w.tracer(0)
        for y in range(self.rowsInMaze):
            for x in range(self.columnsInMaze):
                if self.mazelist[y][x] == OBSTACLE:
                    self.drawCenteredBox(x + self.xTranslate, -y + self.yTranslate, 'orange')
        self.t.color('black')
        self.t.fillcolor('blue')
        self.w.update()
        self.w.tracer(1)

    def drawCenteredBox(self, x, y, color):
        self.t.up()
        self.t.goto(x - .5, y - .5)
        self.t.color(color)
        self.t.fillcolor(color)
        self.t.setheading(90)
        self.t.down()
        self.t.begin_fill()
        for i in range(4):
            self.t.forward(1)
            self.t.right(90)
        self.t.end_fill()

    def updatePosition(self, row, col, val = None):
        if val:
            self.mazelist[row][col] = val

        self.moveTurtle(col, row)

        if val == PART_OF_PATH:
            color = 'green'
        elif val == OBSTACLE:
            color = 'red'
        elif val == TRIED:
            color = 'black'
        elif val == DEAD_END:
            color = 'red'
        else:
            color = None

        if color:
            self.dropBreadcrumb(color)

    def moveTurtle(self, x, y):
        mazeX = x + self.xTranslate 
        mazeY = -y + self.yTranslate
        self.t.up()
        self.t.setheading(self.t.towards(mazeX, mazeY))
        self.t.goto(mazeX, mazeY)

    def dropBreadcrumb(self, color):
        self.t.dot(10, color)

    def isExit(self, row, col):
        return row == 0 or row == self.rowsInMaze-1 or col == 0 or col == self.columnsInMaze-1

    def __getitem__(self, idx):
        return self.mazelist[idx]



def searchFrom(maze, startRow, startCol):
    maze.updatePosition(startRow, startCol)

    if maze[startRow][startCol] in (OBSTACLE, TRIED, DEAD_END):
        return False

    if maze.isExit(startRow, startCol):
        maze.updatePosition(startRow, startCol, PART_OF_PATH)
        return True
    
    maze.updatePosition(startRow, startCol, TRIED)

    found = searchFrom(maze, startRow-1, startCol) or searchFrom(maze, startRow+1, startCol) or searchFrom(maze, startRow, startCol-1) or searchFrom(maze, startRow, startCol+1)

    if found:
        maze.updatePosition(startRow, startCol, PART_OF_PATH)
    else:
        maze.updatePosition(startRow, startCol, DEAD_END)

    return found



myMaze = Maze('maze1.dat')
myMaze.drawMaze()
myMaze.updatePosition(myMaze.startRow, myMaze.startCol)
searchFrom(myMaze, myMaze.startRow, myMaze.startCol)
myMaze.w.exitonclick()

