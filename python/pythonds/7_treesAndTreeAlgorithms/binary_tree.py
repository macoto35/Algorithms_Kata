class BinaryTree:
    def __init__(self, key):
        self.key = key
        self.left = self.right = None

    def insertLeft(self, new):
        node = BinaryTree(new)
        if self.left is None:
            self.left = node
        else:
            node.left = self.left
            self.left = node

    def insertRight(self, new):
        node = BinaryTree(new)
        if self.right is None:
            self.right = node
        else:
            node.right = self.right
            self.right = node

    def getLeft(self):
        return self.left

    def getRight(self):
        return self.right

    def setRoot(self, key):
        self.key = key

    def getRoot(self):
        return self.key
