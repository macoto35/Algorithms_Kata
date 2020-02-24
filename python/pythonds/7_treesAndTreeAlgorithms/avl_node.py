class AvlNode:
    def __init__(self, key, payload, leftChild = None, rightChild = None, parent = None):
        self.key = key
        self.payload = payload
        self.balanceFactor = 0
        self.leftChild = leftChild
        self.rightChild = rightChild
        self.parent = parent

    def __iter__(self):
        if self:
            if self.hasLeftChild():
                for e in self.leftChild:
                    yield e
            yield self
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

    def replaceNodeData(self, key, payload, leftCihld, rightCihld):
        self.key = key
        self.payload = payload
        self.leftChild = leftChild
        if self.leftChild:
            self.leftChild.parent = self
        self.rightChild = rightChild
        if self.rightChild:
            self.rightChild.parent = self

    def findSuccessor(self):
        if self.hasRightChild():
            return self.rightChild._findMin()
        elif self.hasLeftChild():
            left = self.leftChild

            if left.hasRightChild():
                return left.rightChild._findMin()
            else:
                return left
        else:
            return None

    def _findMin(self):
        if self.hasLeftChild():
            return self.leftChild._findMin()
        else:
            return self

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
            elif self.isRightChild():
                self.parent.rightChild = child

