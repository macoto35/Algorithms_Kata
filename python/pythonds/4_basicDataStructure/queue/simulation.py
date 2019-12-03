from queue import Queue
from printer import Printer
from task import Task
from random import randrange

def simulation(numOfStd, pagePerMinute):
    labPrinter = Printer(pagePerMinute)
    printerQueue = Queue()
    waitingTimes = []
    currentSecond = 0
    taskCnt = numOfStd * 2

    while True:
        if newPrintTask() and taskCnt > 0:
            printerQueue.enqueue(Task(currentSecond))
            taskCnt -= 1

        if not labPrinter.busy() and not printerQueue.isEmpty():
            nextTask = printerQueue.dequeue()
            waitingTimes.append(nextTask.waitTime(currentSecond))
            labPrinter.startNext(nextTask)

        if taskCnt == 0 and not labPrinter.busy() and printerQueue.isEmpty():
            break

        labPrinter.tick()
        currentSecond += 1

    avgWait = sum(waitingTimes) / len(waitingTimes)
    print("Average Wait %6.2f seconds %3d tasks ramaining"%(avgWait, printerQueue.size()))

def newPrintTask():
    return randrange(1, 181) == 180

'''for i in range(10):
    #simulation(3600, 5)
    simulation(3600, 10)'''

for i in range(10):
    simulation(20, 10)

