from queue import Queue

def hotPotato(names, num):
    q = Queue();

    for name in names:
        q.enqueue(name)

    while q.size() > 1:
        for i in range(num):
            data = q.dequeue()
            print(i, ':', data)
            q.enqueue(data)
        
        print('dequeue:', q.dequeue())
    
    return q.dequeue()

print(hotPotato(["Bill","David","Susan","Jane","Kent","Brad"],7))

