from progress_animation import ProgressAnimation

def mergeSort(arr, st, ed, tarr, pa):

    if st >= ed:
        return

    mid = (st + ed) // 2
    mergeSort(arr, st, mid, tarr, pa)
    mergeSort(arr, mid + 1, ed, tarr, pa)

    pa.turtle_draw(arr, tarr, [i for i in range(st, ed+1)])
    merge(arr, st, mid + 1, ed)
    pa.turtle_draw(arr, tarr, [i for i in range(st, ed+1)])

def merge(arr, st, mid, ed):
    tmp = []
    i = st
    j = mid
    
    while i < mid or j <= ed:
        while j <= ed and (i >= mid or arr[j] <= arr[i]):
            tmp.append(arr[j])
            j += 1

        while i < mid and (j > ed or arr[j] > arr[i]):
            tmp.append(arr[i])
            i += 1

    j = 0
    for i in range(st, ed + 1):
        arr[i] = tmp[j]
        j += 1

pa = ProgressAnimation()
arr = [54, 26, 93, 17, 77, 31, 44, 55, 20]
tarr = pa.turtle_init(arr)
mergeSort(arr, 0, len(arr) - 1, tarr, pa)
print(arr)
pa.enable_exitonclick()
