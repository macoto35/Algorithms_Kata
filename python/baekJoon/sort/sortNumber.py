'''
Q: N개의 수가 주어졌을 때, 오름차순으로 정렬
I: 첫째 줄에 수의 개수 N(1<=N<=1,000), 둘째 줄부터 N개의 줄에는 숫자 (정수 N<=|1,000|, 중복되지 않는다)
O: 첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력
'''
#arr=[];exec("arr.append(int(input()));"*int(input()));arr.sort();print('\n'.join(map(str,arr)))
[*map(print,sorted(eval('int(input()),'*int(input()))))]

'''
arr=[]
exec("arr.append(int(input()));"*int(input()))

# bubble sort: compare 2 elements at time and swap if the 2nd element is larger than the first
l = len(arr)
while l > 1:
    for i in range(1, l):
        if arr[i-1] > arr[i]:
            arr[i-1], arr[i] = arr[i], arr[i-1]
    l -= 1
print(arr)

# insertion sort: take a number from an array, put it into a new array in a sorted way
for i in range(1, len(arr)):
    j = i
    while j >= 1:
        if arr[j-1] > arr[j]:
            arr[j-1], arr[j] = arr[j], arr[j-1]
            j -= 1
        else:
            break
print(arr)'''
