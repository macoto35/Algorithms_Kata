
def mergeSort(B, st, ed, A):
    print('--->enter mergerSort: ', B, A, st, ed)
    if (ed - st < 2):
        return

    mid = (st + ed) // 2
    mergeSort(A, st, mid, B)
    mergeSort(A, mid, ed, B)
    
    merge(B, st, mid, ed, A)

def merge(A, st, mid, ed, B):
    print('merge start: ', A, st, mid, ed, B)
    i = st
    j = mid

    for k in range(st, ed):
        if i < mid and (j >= ed or A[i] <= A[j]):
            B[k] = A[i]
            i += 1
        else:
            B[k] = A[j]
            j += 1
    print('merge end: ', A, st, mid, ed, B)

#A = [12, 59, 34, 23, 17, 61, 31, 14]
A = [59, 12, 34, 23, 2]
B = A[0:]
mergeSort(B, 0, len(A), A)

print(A, B)
