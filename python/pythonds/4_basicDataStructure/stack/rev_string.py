from stack import Stack

# use stack to reverse string
def revstring(mystr):
    stack = Stack()
    for c in mystr:
        stack.push(c)

    result = ''
    while stack.isEmpty() == False:
        result += stack.pop()

    return result

def isEqual(str1, str2):
    if str1 == str2:
        print('"', str1, '" and "', str2, '" are equal')
    else:
        raise ValueError

isEqual(revstring('abc'), 'cba')
isEqual(revstring('python'), 'nohtyp')
isEqual(revstring('this is a test'), 'tset a si siht')

