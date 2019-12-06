from node import Node

class OrderedList:
    def __init__(self):
        self.head = None

    # isEmpty() tests to see whether the list is empty. It needs no parameters and returns a boolean value.
    def isEmpty(self):
        return self.head is None

    # size() returns the number of items in the list. It needs no parameters and returns an integer.
    def size(self):
        length = 0
        current = self.head
        
        while current is not None:
            length += 1
            current = current.getNext()
        
        return length
    
    # index(item) returns the position of item in the list. It needs the item and returns the index. Assume the item is in the list.
    def index(self, item):
        idx = 0
        current = self.head

        while current is not None:
            if current.getData() == item:
                return idx
            
            if current.getData() > item:
                break

            idx += 1
            current = current.getNext()
        
        return None

    # search(item) searches for the item in the list. It needs the item and returns a boolean value.
    def search(self, item):
        return self.index(item) is not None
    
    # add(item) adds a new item to the list making sure that the order is preserved. It needs the item and returns nothing. Assume the item is not already in the list.
    def add(self, item):
        newnode = Node(item)
        previous = None
        current = self.head

        while current is not None:
            if current.getData() > item:
                break
            previous = current
            current = current.getNext()

        if previous is not None:
            previous.setNext(newnode)
        else:
            self.head = newnode
        newnode.setNext(current)

    # remove(item) removes the item from the list. It needs the item and modifies the list. Assume the item is present in the list.
    def remove(self, item):
        return self._remove(item)

    # pop() removes and returns the last item in the list. It needs nothing and returns an item. Assume the list has at least one item.
    def pop(self):
        return self._remove()

    # pop(pos) removes and returns the item at position pos. It needs the position and returns the item. Assume the item is in the list.
    def pop_pos(self, pos):
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
        
        if previous is not None:
            previous.setNext(current.getNext())
        else:
            self.head = current.getNext()

        return current.getData()

