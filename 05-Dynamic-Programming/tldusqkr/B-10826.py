import sys
input = sys.stdin.readline

def fibo(n):
    x = 0
    y = 1
    for _ in range(n):
        x, y = y, x+y
    return x

print(fibo(int(input())))