class QueueArray:
    size = 5
    arr = [None] * size
    write = -1
    read = -1

    def toString(self):
        if self._empty():
            return None

        result = []
        i = self.read

        while(i != self.write):
                result.append(str(self.arr[i]))
                i = (i + 1) % self.size
        result.append(str(self.arr[i]))
        
        return ','.join(result)

    def _full(self):
        return (self.write + 1) % self.size == self.read

    def _empty(self):
        return self.read == -1

    def enqueue(self, data):
        if self._full():
            raise IndexError

        if self.read == -1:
            self.read = 0
        
        self.write = (self.write + 1) % self.size
        self.arr[self.write] = data

    def dequeue(self):
        if self._empty():
            return None

        result = self.arr[self.read]

        if self.read == self.write:
            self.read = self.write = -1
        else:
            self.read = (self.read + 1) % self.size

        return result
