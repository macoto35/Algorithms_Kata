i=int(input())

s=11
d=1
while i > 1:
    if s//10 == 1:
        s += (1 if s%2 else 9)
        d = 1
    elif s%10 == 1:
        s += (-9 if s//10%2 else 10)
        d = -1
    else:
        s += d*9
    print(i, ':', s)
    i-=1

print('result: ', s)
