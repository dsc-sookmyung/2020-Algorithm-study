import sys
input = sys.stdin.readline

N = int(input())

mag = list()

for _ in range(N):
    mag.append(int(input()))

count = 1
cmax = mag[N-1]

for i in reversed(mag):
    if i > cmax:
        count += 1
        cmax = i

print(count)