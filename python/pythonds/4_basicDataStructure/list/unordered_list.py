from node import Node
from list import List

class UnorderedList(List):
    def index(self, item):
        idx = 0
        current = self.head
        
        while current is not None:
            if item == current.getData():
                return idx
            
            current = current.getNext()
            idx += 1
        
        return None

    def add(self, data):
        self.insert(data, 0)

    def append(self, data):
        self.insert(data)

    def insert(self, data, idx = -1):
        newnode = Node(data)
        self.length += 1
        
        if idx == 0 or self.head is None:
            # add front
            if self.head is None:
                self.tail = newnode
            newnode.setNext(self.head)
            self.head = newnode
        elif idx == -1:
            #add rear
            self.tail.setNext(newnode)
            self.tail = newnode
        else:
            i = 0
            previous = None
            current = self.head
        
            while current.getNext() is not None:
                if i == idx:
                    # add middle
                    previous.setNext(newnode)
                    newnode.setNext(current)
                    return
                previous = current
                current = current.getNext()
                i += 1
 
