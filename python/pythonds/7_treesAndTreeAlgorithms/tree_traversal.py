from binary_tree import BinaryTree

'''
Traversal: visitation of the nodes
- preorder
- inorder
- postorder
'''
def preorder(tree):
    if tree:
        print(tree.getRoot(), end = ' ')
        preorder(tree.getLeft())
        preorder(tree.getRight())

def inorder(tree):
    if tree:
        inorder(tree.getLeft())
        print(tree.getRoot(), end = ' ')
        inorder(tree.getRight())

def postorder(tree):
    if tree:
        postorder(tree.getLeft())
        postorder(tree.getRight())
        print(tree.getRoot(), end = ' ')


'''
      A
   B    C
 D  E  F  G
'''
root = BinaryTree('A')
root.insertLeft('B')
left = root.getLeft()
left.insertLeft('D')
left.insertRight('E')
root.insertRight('C')
right = root.getRight()
right.insertLeft('F')
right.insertRight('G')

print('preorder:', end = ' ')
preorder(root) # A B D E C F G
print('\ninorder:', end = ' ')
inorder(root) # D B E A F C G
print('\npostorder:', end = ' ')
postorder(root) # D E B F G C A
