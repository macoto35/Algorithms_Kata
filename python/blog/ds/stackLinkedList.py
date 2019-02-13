from node import Node

class StackLinkedList:
    head = None

    def toString(self):
        result = []
        tmp = self.head
        while (tmp is not None):
            result.append(str(tmp.data))
            tmp = tmp.next

        return ','.join(result)

    # addFirst
    def push(self, data):
        node = Node(data)

        node.next = self.head
        self.head = node

    # removeFirst
    def pop(self):
        if self.empty():
            return None
        else:
            delete = self.head
            result = delete.data
            newHead = delete.next

            self.head = newHead

            delete = None
            return result

    def empty(self):
        return self.head is None;

    def peek(self):
        if self.empty():
            return None
        return self.head.data

    def search(self, data):
        tmp = self.head
        idx = 0

        while (tmp is not None):
            if data == tmp.data:
                return idx
            tmp = tmp.next
            idx += 1

        return -1
