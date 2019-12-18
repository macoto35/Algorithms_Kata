import time

def recMC(coinValueList, change, knownResults):
    minCoins = change
    
    if change in coinValueList:
        knownResults[change] = 1
        return 1

    if knownResults[change] > 0:
        return knownResults[change]

    for i in [c for c in coinValueList if c <= change]:
        numCoins = 1 + recMC(coinValueList, change - i, knownResults)

        if numCoins < minCoins:
            minCoins = numCoins
            knownResults[change] = minCoins

    return minCoins

def dpMakeChange(coinValueList, change, minCoins):
    for i in range(1, change + 1):
        minCoins[i] = min([minCoins[i - c] + 1 for c in coinValueList if c <= i])

    return minCoins[change]

def dpMakeChangeTrack(coinValueList, change, minCoins, coinUsed):
    for cents in range(1, change + 1):
        coinCount = cents
        newCoin = 1
        for coin in [c for c in coinValueList if c <= cents]:
            if minCoins[cents - coin] + 1 < coinCount:
                coinCount = minCoins[cents - coin] + 1
                newCoin = coin
        minCoins[cents] = coinCount
        coinUsed[cents] = newCoin
    
    return minCoins[change]

def printCoins(coinUsed, change):
    coin = change
    while coin > 0:
        thisCoin = coinUsed[coin]
        print(thisCoin)
        coin -= thisCoin
'''
start = time.time()
print(recMC([1,5,10,25], 123, [0]*124), time.time() - start)

start = time.time()
print(dpMakeChange([1,5,10,25], 123, [0]*124), time.time() - start)
'''

def main():
    amount = 123
    coinValueList = [1, 5, 10, 21, 25]
    coinCount = [0] * (amount + 1)
    coinsUsed = [0] * (amount + 1)

    print('Making change for', amount, 'requires')
    print(dpMakeChangeTrack(coinValueList, amount, coinCount, coinsUsed), 'coins')
    print('They are:')
    printCoins(coinsUsed, amount)
    print('The used list is as follows:')
    print(coinsUsed)

main()

