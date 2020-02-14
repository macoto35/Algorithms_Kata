from progress_animation import ProgressAnimation

def insertionSort(arr, pa):
    tarr = pa.turtle_init(arr)

    for i in range(1, len(arr)):
        tmp = arr[i]
        j = i
        pa.turtle_insertion_draw(arr, tarr, j, 'blue')
        
        while j > 0 and arr[j - 1] > tmp:
            arr[j] = arr[j - 1]
            j -= 1
            pa.turtle_insertion_draw(arr, tarr, j - 1, 'red')

        arr[j] = tmp
        pa.turtle_insertion_draw(arr, tarr, j, 'blue')

pa = ProgressAnimation()
arr = [54, 26, 93, 17, 77, 31, 44, 55, 20]
insertionSort(arr, pa)
print(arr)
pa.enable_exitonclick()
