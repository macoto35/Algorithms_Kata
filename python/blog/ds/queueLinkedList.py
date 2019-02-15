from node import Node

class QueueLinkedList:
    head = None
    tail = None

    def toString(self):
        result = []
        tmp = self.head

        while(tmp is not None):
            result.append(str(tmp.data))
            tmp = tmp.next

        return ','.join(result)

    # addLast
    def enqueue(self, data):
        node = Node(data)
        
        if self.tail is not None:
            self.tail.next = node

        if self.head is None:
            self.head = node

        self.tail = node

    # removeFirst
    def dequeue(self):
        if self.empty():
            return None

        delete = self.head
        result = delete.data
        newHead = delete.next

        self.head = newHead

        if (newHead is None):
            self.tail = None

        delete = None
        return result


    def empty(self):
        return self.head is None
