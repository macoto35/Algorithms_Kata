
def shellSort(arr):
    gap = len(arr)

    while(gap > 1):
        gap = gap // 3 + 1
        for i in range(gap, len(arr)):
            tmp = arr[i]
            j = i
            while(j >= gap and arr[j - gap] > tmp):
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = tmp
    return arr

print(shellSort([5, 2, 3, 8, 1]))
print(shellSort([62, 83, 18, 53, 7, 17, 95, 86, 47, 69, 25, 28]))
