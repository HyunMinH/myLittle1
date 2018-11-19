'''
def fib(n):
    if n == 0: return 0
    if n == 1: return 1
    return fib(n-1) + fib(n-2)

def printfib(n):
    for i in range(n):
        print(fib(i), end = ',')


num = int(input("몇 번째까지 피보나치 수열을 보시겠습니까: "))
printfib(num)
'''

sum = 0
cnt = 0

with open("sample.txt", "r") as f:
    lines = f.readlines()
    for line in lines:
        sum += int(line)
        cnt += 1

with open("sample.txt", "w") as f:
    f.write(str(sum/cnt))

