def binarySearch(alist, item):
    found = False
    st = 0
    ed = len(alist) - 1

    while st <= ed and not found:
        mid = (st + ed) // 2
        print(st, ed, mid)

        if item == alist[mid]:
            found = True
        elif item < alist[mid]:
            ed = mid - 1
        else:
            st = mid + 1

    return found

def binarySearchRecur(alist, item):
    if len(alist) == 0:
        return False

    mid = len(alist) // 2

    if item == alist[mid]:
        return True
    elif item < alist[mid]:
        return binarySearchRecur(alist[:mid], item)
    else:
        return binarySearchRecur(alist[mid+1:], item)

testlist = [0, 1, 2, 8, 13, 17, 19, 32, 42]
#print(binarySearch(testlist, 3))
#print(binarySearch(testlist, 13))
#print(binarySearch(testlist, 8))
print(binarySearchRecur(testlist, 3))
print(binarySearchRecur(testlist, 13))
print(binarySearchRecur(testlist, 8))
