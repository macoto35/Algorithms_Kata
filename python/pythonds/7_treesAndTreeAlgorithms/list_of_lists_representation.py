class ListOfListsRepresentation:
    def listOfListsRepresentation(self):
        '''
              a
           b     c
         d  e   f

        '''
        myTree = ['a', ['b', ['d', [], []], ['e', [], []]], ['c', ['f', [], []], []]]
        print(myTree)
        print('left subtree = ', myTree[1])
        print('root = ', myTree[0])
        print('right subtree = ', myTree[2])

    def printBinaryTree(self):
        r = self.binaryTree(3)
        self.insertLeft(r, 4)
        self.insertLeft(r, 5)
        self.insertRight(r, 6)
        self.insertRight(r, 7)
        l = self.getLeftChild(r)
        print(r)
        print(l)

        self.setRootVal(l, 9)
        print(r)
        self.insertLeft(l, 11)
        print(r)
        print(self.getRightChild(self.getRightChild(r)))

    def buildtree(self):
        root = self.binaryTree('a')
        
        self.insertLeft(root, 'b')
        left = self.getLeftChild(root)
        self.insertRight(left, 'd')

        self.insertRight(root, 'c')
        right = self.getRightChild(root)
        self.insertLeft(right, 'e')
        self.insertRight(right, 'f')

        #['a', ['b', [], ['d', [], []]], ['c', ['e', [], []], ['f', [], []]]]
        print(root)

    def binaryTree(self, root):
        return [root, [], []]

    def insertLeft(self, root, newBranch):
        t = root.pop(1)
        if len(t) > 1:
            root.insert(1, [newBranch, t, []])
        else:
            root.insert(1, [newBranch, [], []])

        return root
    
    def insertRight(self, root, newBranch):
        t = root.pop(2)
        if len(t) > 1:
            root.insert(2, [newBranch, [], t])
        else:
            root.insert(2, [newBranch, [], []])

        return root
    
    def getRootVal(self, root):
        return root[0]

    def setRootVal(self, root, newVal):
        root[0] = newVal

    def getLeftChild(self, root):
        return root[1]

    def getRightChild(self, root):
        return root[2]

