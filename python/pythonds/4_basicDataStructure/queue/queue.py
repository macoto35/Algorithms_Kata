class Queue:
    def __init__(self):
        self.q = []

    def enqueue(self, item):
        self.q.insert(0, item)

    def dequeue(self):
        return self.q.pop()

    def isEmpty(self):
        return len(self.q) <= 0

    def size(self):
        return len(self.q)
