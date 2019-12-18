class QueueRotate:
    def __init__(self):
        self.q = [None] * 2
        self.r = 0
        self.w = 0
        self.size = 0
        self.capacity = 2

    def enqueue(self, item):
        if self.size == self.capacity:
            self.nq = [None] * self.capacity * 2
            for i in range(self.size):
                self.nq[i] = self.q[self.r]
                self.r = (self.r + 1) % self.capacity
            self.q = self.nq
            self.r = 0
            self.w = self.size
            self.capacity *= 2

        self.q[self.w] = item
        self.w = (self.w + 1) % self.capacity
        self.size += 1

    def dequeue(self):
        deldata = self.q[self.r]
        
        self.r = (self.r + 1) % self.capacity
        self.size -= 1

        return deldata

    def isEmpty(self):
        return self.size == 0
