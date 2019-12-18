class List:
    def __init__(self):
        self.head = None
        self.tail = None
        self.length = 0

    def __str__(self):
        arr = []
        current = self.head
        while current is not None:
            arr.append(str(current.getData()))
            current = current.getNext()

        return '[' + ', '.join(arr) + ']'
    
    # isEmpty() tests to see whether the list is empty. It needs no parameters and returns a boolean value. - O(1)
    def isEmpty(self):
        return self.head is None

    # size() returns the number of items in the list. It needs no parameters and returns an integer. - O(1)/O(n)
    def size(self):
        return self.length
        '''length = 0
        current = self.head
        
        while current is not None:
            length += 1
            current = current.getNext()
        
        return length'''

    # search(item) searches for the item in the list. It needs the item and returns a boolean value. - O(n)
    def search(self, item):
        return self.index(item) is not None

    def slice(self, start, stop):
        idx = 0
        arr = []
        current = self.head

        while current is not None:
            if idx >= start and idx < stop:
                arr.append(current.getData())

            if idx > stop:
                break

            idx += 1
            current = current.getNext()

        return arr

    # remove(item) removes the item from the list. It needs the item and modifies the list. Assume the item is present in the list. - O(n)
    def remove(self, item):
        return self._remove(item)

    # pop() removes and returns the last item in the list. It needs nothing and returns an item. Assume the list has at least one item. - O(n)
    # pop(pos) removes and returns the item at position pos. It needs the position and returns the item. Assume the item is in the list. - O(n)
    def pop(self, pos = None):
        return self._remove(None, pos)

    def _remove(self, item = None, pos = None):
        idx = 0
        previous = None
        current = self.head

        while current is not None:
            if (item is not None and item == current.getData()) or (pos is not None and pos == idx):
                break
            if item is None and pos is None and current.getNext() is None:
                break
            idx += 1
            previous = current
            current = current.getNext()

        if current is None:
            raise ValueError

        self.length -= 1
        if previous is not None:
            previous.setNext(current.getNext())
            if current.getNext() is None:
                self.tail = previous
        else:
            self.head = current.getNext()

        return current.getData()

