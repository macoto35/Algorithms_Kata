#n=0;exec("w=input();a=[i for i, j in zip(w,'?'+w) if i!=j];n=n+min(a.count(i) == 1 for i in a);"*int(input()));print(n)
r=0;exec('s=input();r+=[*s]==sorted(s,key=s.find);'*int(input()));print(r)
