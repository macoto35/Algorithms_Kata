from queue_list import QueueList

def radix_sorting(arr):
    mainBin = QueueList()
    
    digitBins = []
    for i in range(10):
        digitBins.append(QueueList())

    itemLen = 0
    for item in arr:
        itemStr = str(item)
        mainBin.enqueue(itemStr)
        if itemLen < len(itemStr):
            itemLen = len(itemStr)

    for i in range(1, itemLen + 1):
        while mainBin.isEmpty() == False:
            item = mainBin.dequeue()
            try:
                digitBins[int(item[i * -1])].enqueue(item)
            except:
                digitBins[0].enqueue(item)
        for bin in digitBins:
            while bin.isEmpty() == False:
                mainBin.enqueue(bin.dequeue())

    result = []
    while mainBin.isEmpty() == False:
        result.append(int(mainBin.dequeue()))

    return result

assert [15, 24, 33, 42, 51] == radix_sorting([15, 24, 33, 42, 51])
assert [2, 24, 45, 66, 75, 90, 170, 802] == radix_sorting([170, 90, 802, 2, 24, 45, 75, 66])

