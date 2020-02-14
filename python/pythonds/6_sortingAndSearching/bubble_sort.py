from progress_animation import ProgressAnimation

def bubbleSort(arr, pa):
    tarr = pa.turtle_init(arr)
    scanCnt = swapCnt = 0

    for i in range(len(arr) - 1, 0, -1):
        for j in range(i):
            scanCnt += 1
            pa.turtle_draw(arr, tarr, [j, j+1])
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swapCnt += 1
                pa.turtle_draw(arr, tarr, [j, j+1])

    print('scan cnt: ', scanCnt, 'swap cnt: ', swapCnt)

def bubbleSortImproved(arr, pa):
    tarr = pa.turtle_init(arr)
    end = len(arr) - 1
    isSwap = False
    scanCnt = swapCnt = 0

    while end > 0:
        for j in range(end):
            scanCnt += 1
            pa.turtle_draw(arr, tarr, [j, j+1])
            
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                end = j + 1
                swapCnt += 1
                isSwap = True
                pa.turtle_draw(arr, tarr, [j, j+1])
        
        if isSwap is False:
            break

        end -= 1
        isSwap = False

    print('scan cnt: ', scanCnt, 'swap cnt: ', swapCnt)

pa = ProgressAnimation()
arr = [54, 26, 93, 17, 77, 31, 44, 55, 20] #[20, 30, 40, 90, 50, 60, 70, 80, 100, 110]
#bubbleSort(arr, pa)
bubbleSortImproved(arr, pa)
print(arr)
pa.enable_exitonclick()

'''arr1 = [20, 30, 40, 90, 50, 60, 70, 80, 100, 110]#[54, 26, 93, 17, 77, 31, 44, 55, 11]
arr2 = [20, 30, 40, 90, 50, 60, 70, 80, 100, 110]#[54, 26, 93, 17, 77, 31, 44, 55, 11]
bubbleSort(arr1, None)
bubbleSortImproved(arr2, None)'''
