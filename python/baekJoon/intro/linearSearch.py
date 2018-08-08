import time

numbers = []
for a in range(1, 10000001):
    numbers.append(a)

start = time.time()

# start search
x = 10000000
tried = 0
for item in enumerate(numbers):
    tried += 1
    if item == 600:
        print('Find x!')
        break
# end search

end = time.time()

print(end - start)
print ("How many times did you try to get the answer?", tried)
