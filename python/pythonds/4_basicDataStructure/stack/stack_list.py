class Node:
    def __init__(self, item):
        self.data = item
        self.next = None

class StackList:
    def __init__(self):
        self.head = None
        self.length = 0

    def push(self, item):
        newnode = Node(item)
        self.length += 1

        newnode.next = self.head
        self.head = newnode

    def pop(self):
        removenode = self.head
        self.head = self.head.next
        self.length -= 1
        
        return removenode.data

    def peek(self):
        return self.head.data

    def size(self):
        return self.length
    
    def isEmpty(self):
        return self.head is None

s = StackList()
assert True == s.isEmpty()
s.push(11)
s.push(22)
s.push(33)
assert False == s.isEmpty()
assert 3 == s.size()
assert 33 == s.pop()
assert 22 == s.peek()
