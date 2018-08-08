'''arr = [1 for i in range(10036)]
for i in range(1, 10001):
    arr[i + sum(map(int,str(i)))] = 0
    if arr[i]: print(i)'''
r = range(9999); print( *sorted( {*r} - {n + sum(map(int, str(n))) for n in r} ) )
