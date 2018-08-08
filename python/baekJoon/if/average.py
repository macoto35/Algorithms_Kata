n = int(input()); g = [int(i) for i in input().split()]; print('{0:.2f}'.format(sum([i / max(g) * 100 for i in g]) / n))
#input(); *g ,= map(int, input().split()); print('%.2f'%(sum(g)*100/len(g)/max(g)))
