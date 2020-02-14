from progress_animation import ProgressAnimation

def selectionSort(arr, pa):
    tarr = pa.turtle_init(arr)
    scanCnt = swapCnt = 0

    for i in range(len(arr), 1, -1):
        lidx = 0
        eidx = i - 1
        for j in range(1, i):
            scanCnt += 1
            if arr[j] > arr[lidx]:
                lidx = j
            pa.turtle_selection_draw(arr, tarr, j, lidx, eidx)
        
        pa.turtle_selection_draw(arr, tarr, -1, lidx, eidx)
        if lidx != eidx:
            arr[lidx], arr[eidx] = arr[eidx], arr[lidx]
            swapCnt += 1
        pa.turtle_selection_draw(arr, tarr, -1, lidx, eidx)

    print('scan cnt: ', scanCnt, 'swap cnt: ', swapCnt)


pa = ProgressAnimation()
arr = [54, 26, 93, 17, 77, 31, 44, 60, 20]
selectionSort(arr, pa)
print(arr)
pa.enable_exitonclick()
