#exec("print(sum(len(i)*(len(i)+1)//2 for i in input().split('X')));"*int(input()))
exec("print(sum([n*-~n//2for n in map(len,input().split('X'))]));"*int(input()))
