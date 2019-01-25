
def swap(arr, i, j):
    arr[i], arr[j] = arr[j], arr[i]

def partition(arr, le, ri):
    pivot = arr[le]
    j = le

    print('etner partition: ', arr, le, ri)

    for i in range(le + 1, ri):
        print(i, j, arr[i], pivot)
        if arr[i] <= pivot:
            j += 1
            swap(arr, i, j)

    swap(arr, le, j)

    return j

def quickSort(arr, le, ri):
    if le >= ri:
        return;
    
    j = partition(arr, le, ri)

    quickSort(arr, le, j)
    quickSort(arr, j+1, ri)

#arr = [15, 20, 13, 30, 10, 25, 3, 24]
arr = [5, 5, 5, 5, 5]
print('before lomoto quick sort: ', arr)
quickSort(arr, 0, len(arr))
print('after lomoto quick sort: ', arr)
