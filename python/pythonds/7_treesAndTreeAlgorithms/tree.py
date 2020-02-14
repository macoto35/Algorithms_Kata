from list_of_lists_representation import ListOfListsRepresentation
from nodes_and_references import NodesAndReferences

'''
* Definition
- Node: basic unit of tree. 'key' is the ame of the node
- Edge: connects two nodes to show that there is a relationship between them
- Root: the only node in the tree that has no incoming edges
- Path: an ordered list of nodes that are connected by edges
- Children: the set of nodes that have incoming edges from the same node
- Parent: a node is that parent of all the nodes it connects to with outgoing edges
- Sibling: nodes in the tree that are children of the same parent
- Subtree: a set of nodes and edges comprised of a parent and all the descendents of that parent
- Leaf Node: a node that has no children
- Level: the number of edges on the path from the root node. the level of the root node is zero
- Height: the maximum level of any node in the tree
'''

''' * Representation
#list of lists - recursive structure, easy to extend if the tree is more than a binary tree
lolp = ListOfListsRepresentation()
lolp.listOfListsRepresentation()
lolp.printBinaryTree()
lolp.buildtree()
'''
#nodes and reference - oop
nr = NodesAndReferences('a')
print(nr.getRootVal())
print(nr.getLeft())
nr.insertLeft('b')
print(nr.getLeft())
print(nr.getLeft().getRootVal())
nr.insertRight('c')
print(nr.getRight())
print(nr.getRight().getRootVal())
nr.getRight().setRootVal('hello')
print(nr.getRight())
print(nr.getRight().getRootVal())
nr.buildTree()
