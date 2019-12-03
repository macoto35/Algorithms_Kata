from stack import Stack

def matches(open, close):
    opens = '([{'
    closes = ')]}'
    return opens.index(open) == closes.index(close)

def parChecker(str):
    s = Stack()

    for i in range(len(str)):
        if str[i] in '([{':
            s.push(str[i])
        else:
            if s.isEmpty() or not matches(s.peek(), str[i]):
                return False
            s.pop()

    return s.isEmpty()

print('True? ', parChecker('(())'))
print('True? ', parChecker('(()()(()))'))
print('False? ', parChecker('(((('))
print('False? ', parChecker(')'))
print('False? ', parChecker('()('))
print('True? ', parChecker('{{([][])}()}'))
print('True? ', parChecker('[[{{(())}}]]'))
print('True? ', parChecker('[][][](){}'))
print('False? ', parChecker('([)]'))
print('False? ', parChecker('((()]))'))
print('False? ', parChecker('[{()]'))
print('False? ', parChecker('[{('))
