'''hashing - ds can searched in O(1)'''

''' hash function - less collision, easy hash function, evenly distribute '''
# get remainder
def hashFun_remainderMethod(num, m):
   return num % m

# dividing the item into equal size -> add together -> get remainder
def hashFun_foldingMethod(num, m):
    allSum = 0

    while num != 0:
        allSum += num % 100 # 2 digits
        num //= 100

    return allSum % m

# square the num -> extract some portion of the resulting digits -> get remainder
def hashFun_midSquareMethod(num, m):
    sqrstr = str(num * num)
    
    if len(sqrstr) >= 2:
        sqrstr = sqrstr[1:3]

    return int(sqrstr) % 11

# [anagrams have same hash] sum of each character's ascii -> get remainder
def hashFun_string(word, m):
    allSum = 0
    for c in word:
        allSum += ord(c)

    return allSum % m

# sum of each character's ascii with weight -> get remainder
def hashFun_stringWeighting(word, m):
    allSum = 0
    weight = 1
    for c in word:
        allSum += ord(c) * weight
        weight += 1

    return allSum % m



ht = [None] * 11 #hash table
m = 11 # size of table, m slots = 11

'''
nums = [54, 26, 93, 17, 77, 31]
for num in nums:
    idx = hashFun_remainderMethod(num, m)
    ht[idx] = num

# load factor = num of items / tablesize = 6 / 11
print(ht)
'''

#print(hashFun_foldingMethod(4365554601, m))

#print(hashFun_midSquareMethod(44, m))
#print(hashFun_midSquareMethod(9, m))
#print(hashFun_midSquareMethod(2, m))

#print('hash str: ', hashFun_string('cat', m))
#print('hash str anagrams: ', hashFun_string('tac', m))
#print('hash str: ', hashFun_stringWeighting('cat', m))
#print('hash str anagrams: ', hashFun_stringWeighting('tac', m))





''' collision resolution '''
colnums = [54, 26, 93, 17, 77, 31, 44, 55, 20]

'''# open addressing (linear probing) - find the next open slot. clustering issue (if many collisions occur at the same hash value, surrounding slots will be filled)
for num in colnums:
    idx = hashFun_remainderMethod(num, m)
    while ht[idx] is not None:
        idx = (idx + 1) % m # rehashing function
    ht[idx] = num
print(ht)

def findItemFromOpenAddressing(ht, num, m):
    idx = hashFun_remainderMethod(num, m)
    
    while ht[idx] is not None and ht[idx] != num:    
        idx = (idx + 1) % m

    return idx
print('93, idx? ', findItemFromOpenAddressing(ht, 93, m))
print('20, idx? ', findItemFromOpenAddressing(ht, 20, m))'''

'''# open addressing (extend the linear probing) - skip slot, plus 3
for num in colnums:
    idx = hashFun_remainderMethod(num, m)
    while ht[idx] is not None:
        idx = (idx + 3) % m # rehashing function (skip value changed from 1 to 3)
    ht[idx] = num
print(ht)'''

'''#quadratic probing
for num in colnums:
    h = hashFun_remainderMethod(num, m)
    idx = h
    i = 1

    while ht[idx] is not None:
        idx = (h + i ** 2) % m 
        i += 1

    ht[idx] = num
print(ht)'''

#chaining
for num in colnums:
    idx = hashFun_remainderMethod(num, m)
    if ht[idx] is None:
        tmparr = [num]
        ht[idx] = tmparr
    else:
        ht[idx].append(num)
print(ht)


