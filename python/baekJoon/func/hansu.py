'''n=input()
if len(n) < 3: print(n)
else: print(99 + len([i for i in range(100, int(n)+1) if (i//100+i%10)/2==i//10%10]))'''

print(sum(((i//100+i%10)/2==i//10%10) | (i<100)for i in range(1,int(input())+1)))
