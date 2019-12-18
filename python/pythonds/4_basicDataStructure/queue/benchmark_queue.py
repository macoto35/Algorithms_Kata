import time
from queue import Queue
from queue_list import QueueList

def benchmark_q(size):
    st = time.time()
    q = Queue()
    
    for i in range(size):
        q.enqueue(i)

    for i in range(size):
        q.dequeue()
    
    ed = time.time()
    print('queue, elapsed time for ', size, ' times: ', ed - st)

def benchmark_ql(size):
    st = time.time()
    ql = QueueList()
    
    for i in range(size):
        ql.enqueue(i)
    
    for i in range(size):
        ql.dequeue()
    
    ed = time.time()
    print('queue list, elapsed time for ', size, ' times: ', ed - st)


for i in range(5):
    benchmark_q(100000)
    benchmark_ql(100000)
