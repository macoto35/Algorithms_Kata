class StackFixedArray:
    top = 0
    arr = [-1 for i in range(4)]

    def toString(self):
        result = []

        for i in range(self.top):
            result.append(str(self.arr[i]))

        return ','.join(result)

    def push(self, data):
        if self.top >= len(self.arr):
            raise IndexError

        self.arr[self.top] = data
        self.top += 1

    def pop(self):
        if self.empty():
            return None
        
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
            if self.arr[i] == data:
                return i
        return -1
