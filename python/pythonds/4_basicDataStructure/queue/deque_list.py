class Node:
    def __init__(self, item):
        self.data = item
        self.prev = None
        self.next = None

class DequeList:
    def __init__(self):
        self.head = self.tail = None
        self.length = 0

    def __str__(self):
        arr = []
        
        current = self.head
        while current is not None:
            arr.append(str(current.data))
            current = current.next

        return '[' + ', '.join(arr) + ']'

    def addFront(self, item):
        newnode = Node(item)
        self.length += 1

        newnode.prev = self.tail

        if self.tail is None:
            self.head = newnode
        else:
            self.tail.next = newnode
        self.tail = newnode

    def addRear(self, item):
        newnode = Node(item)
        self.length += 1

        newnode.next = self.head

        if self.head is None:
            self.tail = newnode
        else:
            self.head.prev = newnode

        self.head = newnode

    def removeFront(self):
        removenode = self.tail
        self.length -= 1
        
        self.tail = self.tail.prev
        if self.tail is not None:
            self.tail.next = None
        else:
            self.head = None
        
        return removenode.data

    def removeRear(self):
        removenode = self.head
        self.length -= 1
        
        self.head = self.head.next
        if self.head is not None:
            self.head.prev = None
        else:
            self.tail = None

        return removenode.data

    def isEmpty(self):
        return self.head is None

    def size(self):
        return self.length

dl = DequeList()
assert True == dl.isEmpty()
# 4 2 1 3
dl.addFront(1)
dl.addRear(2)
dl.addFront(3)
dl.addRear(4)
assert False == dl.isEmpty()
assert 4 == dl.size()
assert '[4, 2, 1, 3]' == dl.__str__()
'''assert 3 == dl.removeFront()
assert 4 == dl.removeRear()
assert 1 == dl.removeFront()
assert 2 == dl.removeRear()'''
assert 4 == dl.removeRear()
assert 3 == dl.removeFront()
assert 2 == dl.removeRear()
assert 1 == dl.removeFront()
