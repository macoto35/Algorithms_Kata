from tree_node import TreeNode

'''
* map ADT(abstract data type) can be implemented by hashtable as well as binary search tree
Map() Create a new, empty map.
put(key,val) Add a new key-value pair to the map. If the key is already in the map then replace the old value with the new value.
get(key) Given a key, return the value stored in the map or None otherwise.
del Delete the key-value pair from the map using a statement of the form del map[key].
len() Return the number of key-value pairs stored in the map.
in Return True for a statement of the form key in map, if the given key is in the map. 

* Binary Search Tree property
Keys are less than the parent are found in the left subtree.
Keys are greater than the parent are found in the right subtree.
'''
class BinarySearchTree:
    def __init__(self):
        self.root = None
        self.size = 0

    def length(self):
        return self.size

    def __len__(self):
        return self.size

    def __iter__(self):
        return self.root.__iter__()

    def __str__(self):
        return self._inorder(self.root)

    def _inorder(self, node):
        result = ''
        if node:
            result += self._inorder(node.leftChild)
            result += str(node.key) + ', '
            result += self._inorder(node.rightChild)

        return result

    def put(self, key, val):
        if not self.root:
            self.root = TreeNode(key, val)
        else:
            currentNode = self._findSpot(key)
            new = TreeNode(key, val)
            new.parent = currentNode

            if key < currentNode.key:
                currentNode.leftChild = new
            elif key > currentNode.key:
                currentNode.rightChild = new
            else:
                currentNode.replaceNodeData(key, val, currentNode.leftChild, currentNode.rightChild)
        self.size += 1

    def _findSpot(self, key):
        currentNode = self.root
        while currentNode:
            left = currentNode.hasLeftChild()
            right = currentNode.hasRightChild()
            
            if key < currentNode.key and left:
                currentNode = left
            elif key > currentNode.key and right:
                currentNode = right
            else:
                break

        return currentNode

    def get(self, key):
        node = self._get(key)
        return node.payload if node else None

    def _get(self, key):
        currentNode = self._findSpot(key)
        
        if currentNode and currentNode.key == key:
            return currentNode

        return None

    def delete(self, key):
        node = self._get(key)

        if node:
            if node.hasBothChildren():
                # multiple
                s = node.findSuccessor()
                s.spliceOut()
                node.key = s.key
                node.payload = s.payload
            else:
                # no or single
                if self.size == 1:
                    self.root = None
                else:
                    node.spliceOut()
            self.size -= 1
        else:
            raise KeyError('Error, key is not in the tree')

    def __setitem__(self, key, val):
        self.put(key, val)

    def __getitem__(self, key):
        return self.get(key)
    
    def __delitem__(self, key):
        self.delete(key)

    def __contains__(self, key):
        return self.get(key) is not None

