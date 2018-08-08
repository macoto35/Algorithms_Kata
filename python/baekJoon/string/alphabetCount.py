#w=input().upper();s=''.join(i+str(w.count(i))for i in set(w));a1=s[0::2];a2=s[1::2];print(a1[a2.index(max(a2))]if a2.count(max(a2)) == 1 else "?")
#w=input().upper();*s,=map(w.count,map(chr,range(65,91)));print(chr(s.index(max(s))+65)if s.count(max(s))==1 else "?")
s=input().upper();c=s.count;*_,a,b=v=sorted({*s,'?'},key=c);print(v[-(c(a)<c(b))])
