class Stack():
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def peek(self):
        return self.items[self.size()-1]

    def size(self):
        return len(self.items)
    
    def isEmpty(self):
        return True if len(self.items) == 0 else False

convertString = '0123456789ABCDEF'

def toStr(num, base):
    if num < base:
        return convertString[num]
    else:
        return toStr(num//base, base) + convertString[num % base] 

def toStrStack(num, base):
    s = Stack()
    
    while num > 0:
        if num < base:
            s.push(convertString[num])
        else:
            s.push(convertString[num % base])
        num //= base

    result = ''
    while s.isEmpty() == False:
        result += s.pop()

    return result

assert '10' == toStr(16, 16)
assert '5AD' == toStr(1453, 16)
assert '1010' == toStr(10, 2)

assert '10' == toStrStack(16, 16)
assert '5AD' == toStrStack(1453, 16)
assert '1010' == toStrStack(10, 2)

