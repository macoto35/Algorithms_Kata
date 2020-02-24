class TreeNode:
    def __init__(self, key, val, left = None, right = None, parent = None):
        self.key = key
        self.payload = val
        self.leftChild = left
        self.rightChild = right
        self.parent = parent

    def __iter__(self):
        if self:
            if self.hasLeftChild():
                for e in self.leftChild:
                    yield e
            yield self.key
            if self.hasRightChild():
                for e in self.rightChild:
                    yield e

    def hasLeftChild(self):
        return self.leftChild

    def hasRightChild(self):
        return self.rightChild

    def isLeftChild(self):
        return self.parent and self.parent.leftChild == self

    def isRightChild(self):
        return self.parent and self.parent.rightChild == self

    def isRoot(self):
        return not self.parent

    def isLeaf(self):
        return not self.leftChild and not self.rightChild

    def hasAnyChildren(self):
        return self.leftChild or self.rightChild

    def hasBothChildren(self):
        return self.leftChild and self.rightChild

    def replaceNodeData(self, key, value, lc, rc):
        self.key = key
        self.payload = value
        self.leftChild = lc
        self.rightChild = rc
        if self.hasLeftChild():
            self.leftChild.parent = self
        if self.hasRightChild():
            self.rightChild.parent = self

    def findSuccessor(self):
        if self.hasRightChild():
            return self.rightChild.findMin()
        elif self.hasLeftChild():
            left = self.leftChild
            if left.hasRightChild():
                return left.rightChild.findMin()
            else:
                return left
        else:
            return None

    def findMin(self):
        current = self
        while current.hasLeftChild():
            current = current.leftChild
        return current

    def spliceOut(self):
        left = self.hasLeftChild()
        right = self.hasRightChild()
        child = left if left else right
            
        if child:
            child.parent = self.parent
            if self.isRoot():
                self.replaceNodeData(child.key, child.payload, child.leftChild, child.rightChild)

        if self.parent:
            if self.isLeftChild():
                self.parent.leftChild = child
            else:
                self.parent.rightChild = child
