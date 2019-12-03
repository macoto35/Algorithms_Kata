def n2(arr):
    cnt = 0
    min = arr[0]
    for i in range(len(arr)):
        for j in range(len(arr)):
            cnt += 1
            if arr[i] < arr[j] and arr[i] < min:
                min = arr[i]
    print('n2 running time: ', cnt)
    return min

def n(arr):
    cnt = 0
    min = arr[0]
    for i in range(len(arr)):
        cnt += 1
        if arr[i] < min:
            min = arr[i]
    print('n2 running time: ', cnt)
    return min

arr = [i for i in range(10, 0, -1)]
print(n(arr))
print(n2(arr))

