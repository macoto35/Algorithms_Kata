import time

def recurFibonacci(num):
    if num <= 1:
        return num
    return recurFibonacci(num - 1) + recurFibonacci(num - 2)

def recurFibonacciMemo(num, memo):
    if num <= 1:
        if memo[num] == -1:
            memo[num] = num
        return memo[num]

    if memo[num] == -1:
        memo[num] = recurFibonacciMemo(num - 1, memo) + recurFibonacciMemo(num - 2, memo)

    return memo[num]

def iterFibonacci(num):
    if num <= 1:
        return num

    prev = 0
    cur = 1

    for i in range(2, num + 1):
        prev, cur = cur, prev + cur
    
    return cur


for i in range(40):
    st = time.time()
    print(i, ', [recursive:', recurFibonacci(i), ', time:', time.time() - st, end = '')
    st = time.time()
    print('], [recursive_memo:', recurFibonacciMemo(i, [-1] * (i + 1)), ', time:', time.time() - st, end = '')
    st = time.time()
    print('], [iterative:', iterFibonacci(i), ', time: ', time.time() - st, ']')

