def listsum(arr):
    '''
    # iterative
    total = 0
    for item in arr:
        total += item
    return total
    '''
    if len(arr) == 1:
        return arr[0]
    return arr[0] + listsum(arr[1:])

assert 25 == listsum([1,3,5,7,9])
