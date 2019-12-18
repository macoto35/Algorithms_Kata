from node import Node
from list import List

class OrderedList(List):
    # index(item) returns the position of item in the list. It needs the item and returns the index. Assume the item is in the list. - O(n)
    def index(self, item):
        idx = 0
        current = self.head

        while current is not None:
            if current.getData() == item:
                return idx

            if current.getData() > item:
                break

            current = current.getNext()
            idx += 1

        return None

    # add(item) adds a new item to the list making sure that the order is preserved. It needs the item and returns nothing. Assume the item is not already in the list. - O(n)
    def add(self, item):
        newnode = Node(item)
        self.length += 1
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

