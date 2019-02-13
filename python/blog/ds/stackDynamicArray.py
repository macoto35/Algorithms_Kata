class StackDynamicArray:
    top = 0
    arr = [-1]

    def toString(self):
        return ','.join(map(str, self.arr))

    def _createNewArray(self):
        length = len(self.arr)
        newArr = [-1 for i in range(length * 2)]

        for i in range(length):
            newArr[i] = self.arr[i]

        self.arr = newArr

    def push(self, data):
        if self.top >= len(self.arr):
            self._createNewArray()
        
        self.arr[self.top] = data
        self.top += 1

    def _shrinkArray(self):
        length = len(self.arr)
        newArr = [-1 for i in range(length // 2)]

        for i in range(self.top):
            newArr[i] = self.arr[i]

        self.top -= 1
        result = self.arr[self.top]

        self.arr = newArr

        return result

    def pop(self):
        if self.empty():
            return None
        elif self.top < len(self.arr) // 2:
            return self._shrinkArray()
        else:
            self.top -= 1
            return self.arr[self.top]

    def empty(self):
        return self.top == 0

    def peek(self):
        if self.empty():
            return None
        return self.arr[self.top - 1]

    def search(self, data):
        for i in range(self.top):
            if data == self.arr[i]:
                return i
        return -1
    
