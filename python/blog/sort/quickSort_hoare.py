
def swap(arr, i, j):
    arr[i], arr[j] = arr[j], arr[i]

def partition(arr, le, ri):
    pivot = arr[(le + ri) // 2]
    i = le - 1
    j = ri + 1

    print('enter partition: ', arr, le, ri)

    while True:
        while True:
            i += 1
            print('i? ', i, pivot)
            if i >= ri or arr[i] >= pivot:
                break

        while True:
            j -= 1
            print('j? ', j, pivot)
            if j <= le or arr[j] <= pivot:
                break

        print('i: ', i, ', j: ', j)

        if i >= j:
            return j
        swap(arr, i, j)

def quickSort(arr, le, ri):
    if le >= ri:
        return

    j = partition(arr, le, ri)

    quickSort(arr, le, j)
    quickSort(arr, j + 1, ri)

#arr = [15, 20, 13, 30, 10, 25, 3, 24]
#arr = [5, 5, 5, 5, 5]
arr = [1, 2, 3, 4, 5]
print ('before quick sort: ', arr)
quickSort(arr, 0, len(arr) - 1)
print ('after quick sort: ', arr)
