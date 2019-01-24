
def mergeSort(A, B, n):
    width = 1

    while (width < n):
        i = 0
        
        while (i < n):
            merge(A, B, i, i+width, i+2*width)
            i = i + 2 * width
        
        copyArray(A, B, n)
        width *= 2

def merge(A, B, st, mid, ed):
    i = st
    j = mid
    k = st
    while (k < ed):
        if i < mid and (j >= ed or A[i] <= A[j]):
            B[k] = A[i]
            i += 1
        else:
            B[k] = A[j]
            j += 1
        k += 1

def copyArray(A, B, n):
    for i in range(n):
        A[i] = B[i]

A = [12, 59, 34, 23, 17, 61, 31, 14]
B = A[0:]
mergeSort(A, B, len(A))
print(A, B)
