class NodesAndReferences:
    def __init__(self, root):
        self.key = root
        self.left = None
        self.right = None

    def insertLeft(self, newnode):
        node = NodesAndReferences(newnode)
        if self.left is None:
            self.left = node 
        else:
            node.left = self.left
            self.left = node

    def insertRight(self, newnode):
        node = NodesAndReferences(newnode)
        if self.right is None:
            self.right = node
        else:
            node.right = self.right
            self.right = node

    def getRight(self):
        return self.right

    def getLeft(self):
        return self.left

    def setRootVal(self, key):
        self.key = key

    def getRootVal(self):
        return self.key

    '''
            a
       b         c
          d    e   f

    '''
    def buildTree(self):
        root = NodesAndReferences('a')
        root.insertLeft('b')
        root.insertRight('c')
        root.getLeft().insertRight('d')
        root.getRight().insertLeft('e')
        root.getRight().insertRight('f')

        print('[0] root: ', root.getRootVal())
        print('[0] left: ', root.getLeft().getRootVal())
        print('[0] right: ', root.getRight().getRootVal())
        print('[1] left left: ', root.getLeft().getLeft())
        print('[1] left right: ', root.getLeft().getRight().getRootVal())
        print('[1] right left: ', root.getRight().getLeft().getRootVal())
        print('[1] right right: ', root.getRight().getRight().getRootVal())
