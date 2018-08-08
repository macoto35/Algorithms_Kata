'''c = int(input())
while c > 0:
    n = [int(i) for i in input().split()][1:]
    print('{0:.3f}%'.format(len([i for i in n if i > sum(n) / len(n)]) / len(n) * 100))
    c -= 1'''
exec("N,*S=map(int,input().split()); print(S); print('%.3f%%'%(sum(s>sum(S)/N for s in S)/N*100));"*int(input()))
