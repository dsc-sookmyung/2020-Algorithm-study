import sys
input = sys.stdin.readline

N = int(input())
zero = []

for i in range(N):
    num = int(input())
    if num == 0:
        zero.pop()
    else:
        zero.append(num)

print(sum(zero))