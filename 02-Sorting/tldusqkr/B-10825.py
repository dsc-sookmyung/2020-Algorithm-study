import sys

N = int(input())
std = [list(sys.stdin.readline().split()) for _ in range(N)]

std.sort(key = lambda x: (-int(x[1]), int(x[2]), -int(x[3]), x[0]))

for i in std:
    print(i[0])
