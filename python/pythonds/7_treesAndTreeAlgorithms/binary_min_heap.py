class BinaryMinHeap:
    # create new empty binary heap
    def __init__(self):
        self.bh = [0]
        self.length = 0

    # adds a new item to the heap
    def insert(self, k):
        self.bh.append(k)
        self.length += 1
        self._shiftUp(self.length)

    def _shiftUp(self, i):
        while i > 1 and self.bh[self._getParentIdx(i)] > self.bh[i]:
            pidx = self._getParentIdx(i)
            self.bh[pidx], self.bh[i] = self.bh[i], self.bh[pidx]
            i = pidx

    def _getParentIdx(self, i):
        return i // 2

    def _getLeftIdx(self, i):
        return i * 2

    def _getRightIdx(self, i):
        return i * 2 + 1

    # returns the item with the minimum key value, leaving item in the heap
    def findMin(self):
        if self.length == 0:
            return None
        return self.bh[1]

    # returns the item with the minimum key value, removing the item from the heap
    def delMin(self):
        if self.length == 0:
            return None

        minitem = self.bh[1]
        self.bh[1] = self.bh[self.length]
        self.bh.pop()
        self.length -= 1
        self._shiftDown(1)

        return minitem

    def _shiftDown(self, i):
        minIdx = i

        left = self._getLeftIdx(i)
        if left <= self.length and self.bh[left] < self.bh[minIdx]:
            minIdx = left

        right = self._getRightIdx(i)
        if right <= self.length and self.bh[right] < self.bh[minIdx]:
            minIdx = right

        if minIdx != i:
            self.bh[minIdx], self.bh[i] = self.bh[i], self.bh[minIdx]
            self._shiftDown(minIdx)

    # returns true if the heap is empty, false otherwise
    def isEmpty(self):
        return self.length == 0

    # returns the number of items in the heap
    def size(self):
        return self.length

    # builds a new heap from a list of keys
    def buildHeap(self, alist):
        self.bh = [0] + alist[:]
        self.length = len(alist)

        sidx = self.length // 2
        for i in range(sidx, 0, -1):
            self._shiftDown(i)

