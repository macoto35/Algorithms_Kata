from node import Node

class LinkedList:
    head = None
    tail = None
    length = 0

    def toString(self):
        tmp = self.head
        result = []

        while(tmp is not None):
            result.append(str(tmp.data))
            tmp = tmp.next

        return ','.join(result)

    def addFirst(self, input):
        node = Node(input)

        if self.head is not None:
            node.next = self.head
            
        if self.tail is None:
            self.tail = node
        
        self.head = node
        self.length += 1

    def addLast(self, input):
        node = Node(input)

        if self.tail is not None:
            self.tail.next = node
        
        if self.head is None:
            self.head = node

        self.tail = node
        self.length += 1

    def _getNode(self, idx):
        tmp = self.head
        for i in range(idx):
            if tmp is not None:
                tmp = tmp.next
        return tmp

    def addFront(self, input, idx):
        if idx == 0:
            self.addFirst(input)
        elif idx >= self.length:
            self.addLast(input)
        else:
            prev = self._getNode(idx - 1)

            node = Node(input)
            node.next = prev.next
            prev.next = node
            self.length += 1

    def addBack(self, input, idx):
        if idx >= self.length:
            self.addLast(input)
        else:
            current = self._getNode(idx)
            
            node = Node(input)
            node.next = current.next
            current.next = node

            if (node.next is None):
                self.tail = node

            self.length += 1

