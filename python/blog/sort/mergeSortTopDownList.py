
def mergeSort(arr, st, ed):
    if st == ed:
        return [arr[st]]
    
    mid = (ed - st) // 2 + st
    A = mergeSort(arr, st, mid)
    B = mergeSort(arr, mid+1, ed)
    
    return merge(A, B)

def merge(A, B):
    result = []
    i = j = 0

    while(i < len(A) and j < len(B)):
        if(A[i] < B[j]):
            result.append(A[i])
            i += 1
        else:
            result.append(B[j])
            j += 1

    if(i < len(A)):
        result.extend(A[i:])
    else:
        result.extend(B[j:])

    return result

print(mergeSort([12, 59, 34, 23, 17, 61, 31, 14], 0, 7))
