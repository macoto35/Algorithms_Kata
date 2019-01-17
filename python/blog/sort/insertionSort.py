
def insertionSort(arr):
    for i in range(1, len(arr)):
        tmp = arr[i];
        j = i - 1;
        
        while (j >= 0 and arr[j] > tmp):
            arr[j + 1] = arr[j]
            j -= 1
        
        arr[j + 1] = tmp
    
    return arr

print(insertionSort([5,2,1,8,3,3]));
