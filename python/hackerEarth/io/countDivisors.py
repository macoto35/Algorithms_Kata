'''
You have been given 3 integers - l, r and k.
Find how many numbers between l and r (both inclusive) are divisible by k.
You do not need to print these numbers, you just have to find their count.

Input Format
The first and only line of input contains 3 space separated integers l, r and k.

Output Format
Print the required answer on a single line.

Constraints
1≤l≤r≤1000
1≤k≤1000

SAMPLE INPUT
1 10 1

SAMPLE OUTPUT
10
'''
l,r,k=map(int,input().split());print(sum([1*(l!=r)for i in range(l,r+1,k)]))
