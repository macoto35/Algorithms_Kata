from random import *

def swap(arr, i, j):
    arr[i], arr[j] = arr[j], arr[i]

def findPivot(arr, le, ri):
    idx = randint(le, ri - 1)
    swap(arr, le, idx)

    return arr[le]

def partition(arr, le, ri):
    pivot = findPivot(arr, le, ri)
    j = k = le

    print('enter partition: ', arr, le, ri)

    for i in range(le + 1, ri):
        print(i, j, k, arr[i], pivot)
        if arr[i] < pivot:
            k += 1
            swap(arr, i, k)
            swap(arr, j, k)
            j += 1
        elif arr[i] == pivot:
            k += 1
            swap(arr, i, k)
    #swap(arr, le, j)

    print('end partition: ', arr, le, ri)
    print('j / k? ', j, k)
    return (j, k)

def quickSort(arr, le, ri):
    if le >= ri:
        return;
    
    j, k = partition(arr, le, ri)

    quickSort(arr, le, j)
    quickSort(arr, k+1, ri)

arr = [15, 20, 13, 30, 10, 25, 3, 24]
#arr = [5, 5, 5, 5, 5]
#arr = [4, 3, 2, 1]
print('before lomoto quick sort: ', arr)
quickSort(arr, 0, len(arr))
print('after lomoto quick sort: ', arr)
