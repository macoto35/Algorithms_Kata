import operator
from binary_tree import BinaryTree

class Stack:
    def __init__(self):
        self.s = []

    def push(self, data):
        self.s.append(data)

    def pop(self):
        return self.s.pop()

    def isEmpty(self):
        return len(self.s) == 0

def buildParseTree(fpexp):
    node = BinaryTree(None)
    parents = Stack()

    for c in fpexp.split():
        if c == '(':
            # (: create left -> push current node to stack -> descending to left
            node.insertLeft(None)
            parents.push(node)
            node = node.getLeft()
        elif c == ')':
            # ): pop node from stack -> ascending to root
            if parents.isEmpty() is False:
                node = parents.pop()
        elif c in ['+', '-', '*', '/']:
            # operator: set value -> create right -> push current node to stack -> descending to right
            node.setRoot(c)
            node.insertRight(None)
            parents.push(node)
            node = node.getRight()
        else:
            # operand: number, set value -> pop node from stack -> ascending to root
            try:
                node.setRoot(int(c))
                node = parents.pop()
            except ValueError:
                raise ValueError("token '{}' is not a valid integer. ".format(c))

    return node

def evaluate(parseTree):
    opers = {'+': operator.add, '-': operator.sub, '*': operator.mul, '/': operator.truediv}

    left = parseTree.getLeft()
    right = parseTree.getRight()

    if left and right:
        fn = opers[parseTree.getRoot()]
        return fn(evaluate(left), evaluate(right))
    else:
        return parseTree.getRoot()

def postorderEvaluate(parseTree):
    opers = {'+': operator.add, '-': operator.sub, '*': operator.mul, '/': operator.truediv}
    
    if parseTree:
        left = postorderEvaluate(parseTree.getLeft())
        right = postorderEvaluate(parseTree.getRight())

        if left and right:
            return opers[parseTree.getRoot()](left, right)
        else:
            return parseTree.getRoot()

def printexp(parseTree):
    sval = ''
    if parseTree:
        sval = '(' + printexp(parseTree.getLeft())
        sval += str(parseTree.getRoot())
        sval += printexp(parseTree.getRight()) + ')'

    return sval


pt = buildParseTree("( ( 10 + 5 ) * 3 )")
'''print(pt.getLeft().getLeft().getRoot())
print(pt.getLeft().getRoot())
print(pt.getLeft().getRight().getRoot())
print(pt.getRoot())
print(pt.getRight().getRoot())'''
print(evaluate(pt))
print(postorderEvaluate(pt))
print(printexp(pt))
