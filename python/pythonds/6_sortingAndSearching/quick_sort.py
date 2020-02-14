from progress_animation import ProgressAnimation

def quickSort(arr, st, ed, tarr, pa):
    if st < ed:
        mid = partition(arr, st, ed, tarr, pa)
        
        quickSort(arr, st, mid - 1, tarr, pa)
        quickSort(arr, mid + 1, ed, tarr, pa)

def partition(arr, st, ed, tarr, pa):
    getPivot(arr, st, ed)
    pivot = arr[st]
    i = st + 1
    j = ed

    while i <= j:
        while i < ed and arr[i] < pivot:
            i += 1
        
        while j > st and arr[j] > pivot:
            j -= 1
        
        if i > j:
            break
        
        pa.turtle_draw(arr, tarr, [i, j])
        arr[i], arr[j] = arr[j], arr[i]
        pa.turtle_draw(arr, tarr, [i, j])
        
        i += 1
        j -= 1

    mid = i - 1
    pa.turtle_draw(arr, tarr, [st, mid])
    arr[st], arr[mid] = arr[mid], arr[st]
    pa.turtle_draw(arr, tarr, [st, mid])
    
    return mid

def getPivot(arr, st, ed):
    a = arr[st]
    b = arr[(st + ed) // 2]
    c = arr[ed]

    if a > b:
         idx = mid if b > c else (st if a < c else ed)
    else:
         idx = mid if b < c else (ed if a < c else st)
    
    if st != idx:
        arr[st], arr[idx] = arr[idx], arr[st]

pa = ProgressAnimation()
arr = [54, 26, 93, 17, 77, 31, 44, 55, 20]
tarr = pa.turtle_init(arr)
quickSort(arr, 0, len(arr) - 1, tarr, pa)
print(arr)
pa.enable_exitonclick()
