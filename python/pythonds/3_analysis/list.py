import timeit

def list_concat():
    l = []
    for i in range(1000):
        l = l + [i]

def list_append():
    l = []
    for i in range(1000):
        l.append(i)

def list_comprehension():
    l = [i for i in range(1000)]

def list_range():
    l = list(range(1000))


t1 = timeit.Timer("list_concat()", "from __main__ import list_concat")
print("list concat ", t1.timeit(number=1000), "milliseconds")
t2 = timeit.Timer("list_append()", "from __main__ import list_append")
print("list append ", t2.timeit(number=1000), "milliseconds")
t3 = timeit.Timer("list_comprehension()", "from __main__ import list_comprehension")
print("list comprehension ", t3.timeit(number=1000), "milliseconds")
t4 = timeit.Timer("list_range()", "from __main__ import list_range")
print("list range ", t4.timeit(number=1000), "milliseconds")

popzero = timeit.Timer("x.pop(0)", "from __main__ import x")
popend = timeit.Timer("x.pop()", "from __main__ import x")

x = list(range(2000000))
print('pop zero: ', popzero.timeit(number=1000))
x = list(range(2000000))
print('pop end: ', popend.timeit(number=1000))

print('pop(0)   pop()')
for i in range(1000000,100000001,1000000):
    x = list(range(i))
    pt = popend.timeit(number=1000)
    x = list(range(i))
    pz = popzero.timeit(number=1000)
    print("%15.5f, %15.5f"%(pz, pt))
