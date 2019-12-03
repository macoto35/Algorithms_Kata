from node import Node

class UnorderedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def isEmpty(self):
        return self.head is None

    def size(self):
        count = 0
        current = self.head 
        while current is not None:
            count += 1
            current = current.getNext()
        
        return count

    def search(self, item):
        return self.index(item) is not None

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

    def remove(self, item):
        found = False
        previous = None
        current = self.head
        
        while current is not None:
            if item == current.getData():
                found = True
                break
            previous = current
            current = current.getNext()
        
        if found:
            if previous is None:
                self.head = current.getNext()
            else:
                previous.setNext(current.getNext())
                if current.getNext() is None:
                    self.tail = previous
            current = None

    def pop(self, idx = -1):
        i = 0
        current = self.head
        
        while current.getNext() is not None:
            if i == idx:
                break
            current = current.getNext()
            i += 1

        self.remove(current.getData())
        

