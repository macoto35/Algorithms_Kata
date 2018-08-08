#exec("print('test');"*int(input()))

x,y=map(int, str.split(input()))
distance = y-x
step = 1

while (distance > 0):

'''
https://oeis.org/A000267/b000267.txt
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37
1 2 3 3 4 4 5 5 5 6  6  6  7  7  7  7  8  8  8  8  9  9  9  9  9  10 10 10 10 10 11 11 11 11 11 11 12
1 1 2   2   3     3        4           4           5              5              6                 6
'''
