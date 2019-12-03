from stack import Stack

def divideBy2(n):
    if n <= 0:
        return 0

    s = Stack()

    while n > 0:
        s.push(str(n%2))
        n //= 2

    result = ''
    while not s.isEmpty():
        result += s.pop()
    return result

def baseConverter(n, base):
    if n <= 0 or base < 2 or base > 16:
        return 0

    s = Stack()
    digits = '0123456789ABCDEF'

    while n > 0:
        s.push(digits[n % base])
        n //= base

    result = ''
    while not s.isEmpty():
        result += s.pop()
    return result

#for i in range(101):
#    print(i, ': ', divideBy2(i))

#for i in range(101):
#    print(i, ' - 2:', baseConverter(i, 2), ', 8: ', baseConverter(i, 8), ', 16: ', baseConverter(i, 16))

print(baseConverter(256, 16))
