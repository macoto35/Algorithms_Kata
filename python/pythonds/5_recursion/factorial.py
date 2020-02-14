
def recursiveFactorial(num):
    if num <= 1:
        return 1
    return num * recursiveFactorial(num - 1)

for i in range(101):
    print(i, ':', recursiveFactorial(i))

