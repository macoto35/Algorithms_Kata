'''
Akash and Vishal are quite fond of travelling. They mostly travel by railways. They were travelling in a train one day and they got interested in the seating arrangement of their compartment.
The compartment looked something like
6  7| 18 19|
5  8| 17 20|
4  9| 16 21|
                ...until 108
3 10| 15 22|
2 11| 14 23|
1 12| 13 24|
So they got interested to know the seat number facing them and the seat type facing them. The seats are denoted as follows :

Window Seat : WS
Middle Seat : MS
Aisle Seat : AS

You will be given a seat number, find out the seat number facing you and the seat type, i.e. WS, MS or AS.

INPUT
First line of input will consist of a single integer T denoting number of test-cases. Each test-case consists of a single integer N denoting the seat-number.

OUTPUT
For each test case, print the facing seat-number and the seat-type, separated by a single space in a new line.

CONSTRAINTS
1<=T<=105
1<=N<=108

SAMPLE INPUT
2
18
40

SAMPLE OUTPUT
19 WS
45 AS
'''
s='WMAAMW'

n=int(input())
r=n//6-1*(n%6==0)
print(n, r, n-r*6)
