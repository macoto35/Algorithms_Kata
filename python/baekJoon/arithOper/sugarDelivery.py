'''
a = int(input())

def bestDelivery(a):
    memory3 = [-1 for x in range(a//3 + 1)]
    memory5 = [-1 for x in range(a//5 + 1)]

    for x in range(len(memory3)):
        for y in range(len(memory5)):
            if memory3[x] < 0: memory3[x] = 3*x
            if memory5[y] < 0: memory5[y] = 5*y
            if memory3[x] + memory5[y] == a: return x + y

    return -1

print(bestDelivery(a))
'''
i = int(input())
c = 0

while i % 5:
    i -= 3
    c += 1
print(-1 if i < 0 else i // 5 + c)
