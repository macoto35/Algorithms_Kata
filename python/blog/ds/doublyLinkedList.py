from node import Node

class DoublyLinkedList:
    head = None
    tail = None
    length = 0

    def toString(self):
        tmp = self.head
        result = []

        while (tmp is not None):
            result.append(str(tmp.data))
            tmp = tmp.next

        return ','.join(result)

    def addFirst(self, data):
        node = Node(data)

        if (self.head is not None):
            node.next = self.head
            self.head.prev = node

        if (self.tail is None):
            self.tail = node

        self.head = node
        self.length += 1

    def addLast(self, data):
        node = Node(data)

        if (self.tail is not None):
            self.tail.next = node
            node.prev = self.tail

        if (self.head is None):
            self.head = node

        self.tail = node
        self.length += 1

    def _getNode(self, idx):
        if idx < self.length // 2:
            tmp = self.head
            for i in range(idx):
                if tmp is not None:
                    tmp = tmp.next
            return tmp
        else:
            tmp = self.tail
            for i in range(self.length-1, idx, -1):
                if tmp is not None:
                    tmp = tmp.prev
            return tmp

    def addFront(self, data, idx):
        if idx == 0:
            self.addFirst(data)
        elif idx >= self.length:
            self.addLast(data)
        else:
            nextNode = self._getNode(idx)
            prevNode = nextNode.prev
            newNode = Node(data)

            prevNode.next = newNode
            newNode.prev = prevNode

            newNode.next = nextNode
            nextNode.prev = newNode

            self.length += 1

    def addBack(self, data, idx):
        if idx >= self.length:
            self.addLast(data)
        else:
            prevNode = self._getNode(idx)
            nextNode = prevNode.next
            newNode = Node(data)

            prevNode.next = newNode
            newNode.prev = prevNode

            if nextNode is not None:
                newNode.next = nextNode
                nextNode.prev = newNode
            else:
                self.tail = newNode

            self.length += 1

    def removeFirst(self):
        if self.empty():
            return None

        deleteNode = self.head
        result = deleteNode.data
        newHead = deleteNode.next

        if newHead is not None:
            newHead.prev = None
        else:
            self.tail = None
        self.head = newHead

        deleteNode = None
        self.length -= 1

        return result

    def remove(self, idx):
        if idx < 0 or idx >= self.length:
            return None
        elif idx == 0:
            return self.removeFirst()
        else:
            removeNode = self._getNode(idx)
            result = removeNode.data
            prevNode = removeNode.prev
            nextNode = removeNode.next

            if prevNode is not None:
                prevNode.next = nextNode
            else:
                self.head = nextNode

            if nextNode is not None:
                nextNode.prev = prevNode
            else:
                self.tail = prevNode

            removeNode = None
            self.length -= 1

            return result

    def removeLast(self):
        if self.empty():
            return None

        deleteNode = self.tail
        result = deleteNode.data
        newTail = deleteNode.prev

        if newTail is not None:
            newTail.next = None
        else:
            self.head = None
        self.tail = newTail

        deleteNode = None
        self.length -= 1

        return result

    def empty(self):
        return self.head is None

    def size(self):
        return self.length

    def get(self, idx):
        if idx < 0 or idx >= self.length:
            return None
        return self._getNode(idx).data
    
    def indexOf(self, data):
        tmp = self.head

        for i in range(self.length):
            if tmp.data == data:
                return i
            tmp = tmp.next
        
        return -1
