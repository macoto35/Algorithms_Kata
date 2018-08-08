'''a = input(); i = a; idx= 0
while True:
    i = ('%02d%02d'%(int(i), sum(map(int, i))))[1::2]; idx += 1
    if int(a) == int(i): break
print(idx)
'''
r=N=int(input());c=0
while (c<1)+r-N:c+=1;N=N%10*10+N*11//10%10
print(c)
