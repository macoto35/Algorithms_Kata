import time

numbers = []
for a in range(1, 10000001):
    numbers.append(a)

start = time.time()

# start search
x = 10000000

min = 0
mid = round(len(numbers) / 2)
max = len(numbers)

tried = 0
while mid != x:
    if mid > x:
        max = mid
        mid = round((max - min) / 2)
        tried += 1
    elif mid < x:
        min = mid
        mid = round(min + ((max - min) / 2))
        tried += 1
    else:
        print (mid)
        break

# end search

end = time.time()

print(end - start)
print ("How many times did you try to get the answer?", tried)
