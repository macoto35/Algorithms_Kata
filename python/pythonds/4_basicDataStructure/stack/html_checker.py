from stack import Stack

def htmlChecker(str):
    arr = str.split('>')
    s = Stack()

    for item in arr:
        if item != '':
            tag = item[item.index('<'):]

            if tag[0:2] == '</':
                topTag = s.pop()
                if tag[2:] != topTag[1:]:
                    return False
            else:
                s.push(tag)
    return s.isEmpty()

assert True == htmlChecker('<html><head></head><body><div>test!</div></body></html>')
assert False == htmlChecker('<html><head></head><body><div>test!</div></body></wrong></html>')
assert False == htmlChecker('<html><head></head><body><div>test!</div></body><wrong></html>')
