
def bubbleSort(arr):
    swapped = True;
    for i in range(len(arr) - 1, 0, -1):
        swapped = False;
        for j in range(0, i):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swapped = True;
        if (swapped == False):
            break;
    return arr 

print(bubbleSort([5,2,1,8,3,3]))
