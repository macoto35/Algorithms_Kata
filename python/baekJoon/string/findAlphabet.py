#s=input();print(" ".join([str(s.find(chr(i)))for i in range(97, 123)]))
print(*map(input().find,map(chr,range(97,123))))
