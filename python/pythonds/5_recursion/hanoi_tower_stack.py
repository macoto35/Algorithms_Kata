class Node:
    def __init__(self, item):
        self.data = item
        self.next = None

class Stack:
    def __init__(self):
        self.head = None
        self.length = 0

    def __repr__(self):
        result = []
        current = self.head
        while current is not None:
            result.append(str(current.data))
            current = current.next
        return '[' + ','.join(result) + ']'

    def push(self, item):
        newnode = Node(item)
        newnode.next = self.head
        
        self.head = newnode
        self.length += 1

    def pop(self):
        delnode = self.head
        self.head = self.head.next
        self.length -= 1

        return delnode.data

    def size(self):
        return self.length

    def isEmpty(self):
        return self.head is None

def moveTower(height, fromStack, toStack, withStack):
    if height >= 1:
        moveTower(height - 1, fromStack, withStack, toStack)
        moveHeight(fromStack, toStack)
        print('From: ', fromStack, 'To: ', toStack, 'With: ', withStack)
        moveTower(height - 1, withStack, toStack, fromStack)

def moveHeight(fromStack, toStack):
    toStack.push(fromStack.pop())

fromStack = Stack()
fromStack.push(3)
fromStack.push(2)
fromStack.push(1)
moveTower(3, fromStack, Stack(), Stack())

