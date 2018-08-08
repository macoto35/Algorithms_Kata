arr = [int(i) for i in input().split()]
for i in range(len(arr) - 1):
    for j in range(i + 1, len(arr)):
        if arr[i] > arr[j]:
            tmp = arr[i]
            arr[i] = arr[j]
            arr[j] = tmp
print(arr[1])
# print(sorted(input().split(), key=int)[1])
