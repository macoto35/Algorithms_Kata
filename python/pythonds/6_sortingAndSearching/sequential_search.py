def sequentialSearch(alist, item):
    cnt = 0

    for idx in range(len(alist)):
        if item == alist[idx]:
            print(cnt)
            return True
        cnt += 1
    
    print(cnt)
    return False

def orderedSequentialSearch(alist, item):
    cnt = 0
    
    for idx in range(len(alist)):
        if item == alist[idx]:
            print(cnt)
            return True
        if item < alist[idx]:
            break
        cnt += 1
    
    print(cnt)
    return False

testlist = [1, 2, 32, 8, 17, 19, 42, 13, 0]
print(sequentialSearch(testlist, 3))
print(sequentialSearch(testlist, 13))

testlist = [0, 1, 2, 8, 13, 17, 19, 32, 42,]
print(orderedSequentialSearch(testlist, 3))
print(orderedSequentialSearch(testlist, 13))
