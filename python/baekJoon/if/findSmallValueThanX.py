'''# method 1 - simple foreach
n, x = map(int, input().split())
a = input().split()

arr = []
for i in range(n):
    if int(a[i]) < x:
        arr.append(a[i])
print(' '.join(arr))'''

'''#method 2 - using filter
n, x = map(int, input().split())
a = [ i for i in input().split() if int(i) < x ]
print(' '.join(a))'''

# n, x = map(int, input().split()); print(*([i for i in input().split() if int(i) < x]))
