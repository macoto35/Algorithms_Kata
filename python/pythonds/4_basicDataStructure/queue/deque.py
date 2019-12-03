class Deque:
    def __init__(self):
        self.d = []

    def addFront(self, item):
        self.d.append(item)

    def addRear(self, item):
        self.d.insert(0, item)

    def removeFront(self):
        return self.d.pop()

    def removeRear(self):
        return self.d.pop(0)

    def isEmpty(self):
        return self.d == []

    def size(self):
        return len(self.d)
