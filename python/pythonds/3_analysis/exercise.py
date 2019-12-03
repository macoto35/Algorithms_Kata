import timeit
import random

#the list index operator is O(1)
'''for i in range(10000, 100000000, 500000):
    t = timeit.Timer('x[%d]'%(i-1), 'from __main__ import x')

    x = list(range(i))
    li = t.timeit(number=1000)
    print('%d, %13.2f'%(i, li))'''

# get item and set item are O(1) for dictionaries
'''for i in range(10000, 100000000, 500000):
    t_setitem = timeit.Timer('x[%d]=1'%i, 'from __main__ import x')
    t_getitem = timeit.Timer('x[%d]'%i, 'from __main__ import x')

    x = {j: None for j in range(i)}
    setitem_time = t_setitem.timeit(number=1000)
    getitem_time = t_getitem.timeit(number=1000)
    print('%d, %13.2f, %13.2f'%(i, setitem_time, getitem_time))
'''

# compares the performance of the del operator on lists and dictionaries
'''idx = 0
for i in range(10000, 100000000, 20000):
    list_t = timeit.Timer('del x[0:1]', 'from __main__ import x')
    dict_t = timeit.Timer('del y[%d]'%idx, 'from __main__ import y')

    x = list(range(i))
    list_time = list_t.timeit(number=1000)
    y = {j: None for j in range(i)}
    dict_time = dict_t.timeit(number=1)
    print('%d, %13.2f, %13.2f'%(i, list_time, dict_time))
    idx += 1'''

#Given a list of numbers in random order, write an algorithm that works in O(nlog(n)) to find the kth smallest number in the list.
for i in range(10):
    k = random.randint(1, 20)
    list = [random.randint(0, 1000) for i in range(0, 20)]
    print('init list: ', list)
    list.sort()
    print('sorted list: ', list, '%dth smallest number: %d'%(k, list[k-1]))

#Can you improve the algorithm from the previous problem to be linear?


