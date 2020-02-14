from progress_animation import ProgressAnimation 

def shellSort(arr, pa):
    tarr = pa.turtle_init(arr)

    for i in range(1, len(arr)):
        gap = len(arr) // 2 ** i

        if gap < 1:
            break
        
        gapInsertionSort(arr, gap, tarr, pa)

def gapInsertionSort(arr, gap, tarr, pa):
    for i in range(gap, len(arr)):
        curval = arr[i]
        pos = i
        
        while arr[pos - gap] > curval and pos - gap >= 0:
            pa.turtle_draw(arr, tarr, [pos, pos - gap])
            arr[pos] = arr[pos - gap]
            pa.turtle_draw(arr, tarr, [pos, pos - gap])
            pos -= gap

        arr[pos] = curval
        pa.turtle_draw(arr, tarr, [pos])

pa = ProgressAnimation()
arr = [54, 26, 93, 17, 77, 31, 44, 55, 20]
shellSort(arr, pa)
print(arr)
pa.enable_exitonclick()
