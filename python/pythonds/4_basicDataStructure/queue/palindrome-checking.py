from deque import Deque

def palchecker(str):
    q = Deque()

    for c in str:
        if c != ' ':
            q.addFront(c)

    while q.size() > 1:
        if q.removeRear() != q.removeFront():
            return False
    return True

assert False == palchecker('lsdkjfskf')
assert True == palchecker('radar')
assert False == palchecker('rader')
assert True == palchecker('I PREFER PI')
