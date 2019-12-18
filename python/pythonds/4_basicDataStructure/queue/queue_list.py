class Node:
    def __init__(self, item):
        self.data = item
        self.next = None

class QueueList:
    def __init__(self):
        self.head = None
        self.tail = None

    def enqueue(self, item):
        newnode = Node(item)

        if self.head is None:
            self.head = newnode

        if self.tail is not None:
            self.tail.next = newnode

        self.tail = newnode

    def dequeue(self):
        if self.isEmpty():
            return

        delnode = self.head
        self.head = self.head.next

        return delnode.data

    def isEmpty(self):
        return self.head is None

    def size(self):
        length = 0
        current = self.head

        while current is not None:
            length += 1
            current = current.next
        
        return length

'''
# TEST
q = QueueList()
print('size: ', q.size())
print('is empty: ', q.isEmpty())
q.enqueue('A')
q.enqueue('B')
q.enqueue('C')
print('size: ', q.size())
print('is empty: ', q.isEmpty())
print('dequeue: ', q.dequeue())
print('dequeue: ', q.dequeue())
print('dequeue: ', q.dequeue())
print('size: ', q.size())
print('is empty: ', q.isEmpty())
'''
