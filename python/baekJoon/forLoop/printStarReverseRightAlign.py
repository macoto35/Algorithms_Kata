a = int(input())
for i in range(a, 0, -1): print('{0}{1}'.format(' '*(a-i), '*' * i))
