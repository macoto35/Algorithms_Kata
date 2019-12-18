from queue import Queue
from random import randint

def hotPotato(names):
    q = Queue();

    for name in names:
        q.enqueue(name)

    while q.size() > 1:
        num = randint(1, 10)
        for i in range(num):
            data = q.dequeue()
            print(i, ':', data)
            q.enqueue(data)
        
        print('num: ', num, ', dequeue:', q.dequeue())
    
    return q.dequeue()

print(hotPotato(["Bill","David","Susan","Jane","Kent","Brad"]))

