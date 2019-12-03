from deque import Deque

def palchecker(str):
    q = Deque()

    for c in str:
        q.addFront(c)

    while q.size() > 1:
        if q.removeRear() != q.removeFront():
            return False
    return True

print('lsdkjfskf:', palchecker('lsdkjfskf'))
print('radar:', palchecker('radar'))
print('rader:', palchecker('rader'))
