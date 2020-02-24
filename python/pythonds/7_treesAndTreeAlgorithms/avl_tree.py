from avl_node import AvlNode

'''
* balanced binary search tree = AVL tree
- using balanceFactor = height(leftSubTree) - height(rightSubTree)
'''
class AvlTree:
    def __init__(self):
        self.root = None
        self.size = 0

    def length(self):
        return self.size

    def __len__(self):
        return self.size

    def __str__(self):
        return self._inorder(self.root)

    def _inorder(self, node):
        result = ''
        if node:
            result += self._inorder(node.leftChild)
            result += '[' + str(node.key) + ',' + str(node.balanceFactor) + '], '
            result += self._inorder(node.rightChild)

        return result

    def __iter__(self):
        return self.root.__iter__()

    def put(self, key, payload):
        new = AvlNode(key, payload)
        if not self.root:
            self.root = new
            self.size += 1
        else:
            node = self._findNode(key)
            new.parent = node
            
            if node.key == key:
                node.replaceNodeData(key, payload, node.leftChild, node.rightChild)
            elif node.key > key:
                node.leftChild = new
                self._updateBalance(node.leftChild)
                self.size += 1
            else:
                node.rightChild = new
                self._updateBalance(node.rightChild)
                self.size += 1

    def get(self, key):
        node = self._get(key)
        return node.payload if node else None

    def _get(self, key):
        node = self._findNode(key)

        if node and node.key == key:
            return node
        return None

    def delete(self, key):
        node = self._findNode(key)

        if node:
            if node.hasAnyChildren():
                s = node.findSuccessor()
                self._updateBalanceDelete(s)
                s.spliceOut()
                node.key = s.key
                node.payload = s.payload
                s = None
            else:
                if node.isRoot():
                    self.root = None
                else:
                    self._updateBalanceDelete(node)
                    self.spliceOut()
                node = None
            self.size -= 1
        else:
            raise ValueError('Cannot find value by key: ' + str(key))

    def _findNode(self, key):
        currentNode = self.root

        while currentNode is not None:
            left = currentNode.hasLeftChild()
            right = currentNode.hasRightChild()
            if key < currentNode.key and left:
                currentNode = left
            elif key > currentNode.key and right:
                currentNode = right
            else:
                break
        
        return currentNode

    def _updateBalance(self, node):
        if node.balanceFactor > 1 or node.balanceFactor < -1:
            self._rebalance(node)
            return

        if node.parent is not None:
            if node.isLeftChild():
                node.parent.balanceFactor += 1
            elif node.isRightChild():
                node.parent.balanceFactor -= 1
            
            if node.parent.balanceFactor != 0:
                self._updateBalance(node.parent)

    def _updateBalanceDelete(self, node):
        if node.parent is not None:
            if node.isLeftChild():
                node.parent.balanceFactor -= 1
            elif node.isRightChild():
                node.parent.balanceFactor += 1

            if node.parent.balanceFactor == 0:
                self._updateBalanceDelete(node.parent)

            if node.parent.balanceFactor > 1 or node.parent.balanceFactor < -1:
                newroot = self._rebalance(node.parent)
                self._updateBalanceDelete(newroot)

    def _rebalance(self, node):
        if node.balanceFactor < 0:
            '''
            A(-2)            A(-2)                C(0)
                  B(1)   ->     C(-1)    ->    A(0)    B(0)
                C(0)               B(0)
            '''
            if node.rightChild and node.rightChild.balanceFactor > 0:
                self._rotateRight(node.rightChild)
            return self._rotateLeft(node)
        elif node.balanceFactor > 0:
            '''
                  A(2)            A(2)              C(0)
            B(-1)        ->     C(1)      ->    B(0)    A(0)
                C(0)         B(0)
            '''
            if node.leftChild and node.leftChild.balanceFactor < 0:
                self._rotateLeft(node.leftChild)
            return self._rotateRight(node)

    def _rotateLeft(self, node):
        '''
          <-
           E                    C               
         F    C      ->     E      B
            D   B         F   D      A
                  A
        '''
        # move(C) node right -> root
        newroot = node.rightChild
        newroot.parent = node.parent
        if node.isRoot():
            self.root = newroot
        else:
            if node.isLeftChild():
                newroot.parent.leftChild = newroot
            else:
                newroot.parent.rightChild = newroot
        
        # move(E) newroot left -> node right
        node.rightChild = newroot.leftChild
        if node.rightChild:
            node.rightChild.parent = node
        
        # move(E) root -> newroot left
        node.parent = newroot
        newroot.leftChild = node

        # update balance factor for E and C
        node.balanceFactor = node.balanceFactor + 1 - min(0, newroot.balanceFactor)
        newroot.balanceFactor = newroot.balanceFactor + 1 + max(0, node.balanceFactor)

        return newroot

    def _rotateRight(self, node):
        '''
           ->
           E                    C               
         C    F      ->     B      E
       B   D              A      D   F
     A
        '''
        # move (C) node left -> root
        newroot = node.leftChild
        newroot.parent = node.parent
        if node.isRoot():
            self.root = newroot
        else:
            if node.isLeftChild():
                newroot.parent.leftChild = newroot
            else:
                newroot.parent.rightChild = newroot

        # move(D) newroot right -> node left
        node.leftChild = newroot.rightChild
        if node.leftChild:
            node.leftChild.parent = node

        # move(E) root -> newroot right
        node.parent = newroot
        newroot.rightChild = node

        # update balance factor for E and C
        node.balanceFactor = node.balanceFactor - 1 - max(0, newroot.balanceFactor)
        newroot.balanceFactor = newroot.balanceFactor - 1 + min(0, node.balanceFactor)

        return newroot

    def __setitem__(self, key, payload):
        self.put(key, payload)

    def __getitem__(self, key):
        return self.get(key)

    def __delitem__(self, key):
        self.delete(key)

    def __contains__(self, key):
        return self.get(key) is not None
