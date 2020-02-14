
# extra-space
def recurRevListExtra(arr, newarr):
    if len(arr) == 0:
        return

    newarr.append(arr.pop())
    return recurRevListExtra(arr, newarr)

# in-space
def recurRevListIn(arr, st, mid, ed):
    if st == mid:
        return

    arr[st], arr[ed] = arr[ed], arr[st]
    return recurRevListIn(arr, st + 1, mid, ed - 1)


'''arr = [1, 2, 3, 4, 5]
newarr = []
print('Before recurRevListExtra: arr - ', arr, 'newarr - ', newarr)
recurRevListExtra(arr, newarr)
print('After recurRevListExtra: arr - ', arr, 'newarr - ', newarr)'''

arr = [1, 2, 3, 4, 5]
print('Before recurRevListIn: arr - ', arr)
recurRevListIn(arr, 0, len(arr) // 2, len(arr) - 1)
print('After recurRevListIn: arr - ', arr)

