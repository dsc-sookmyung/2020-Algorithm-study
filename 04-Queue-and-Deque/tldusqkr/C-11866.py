from collections import deque
import sys

n, k = map(int, sys.stdin.readline().split())

s = deque([])

for i in range(1, n+1):
    s.append(i)

print('<', end='')
while s:
    for i in range(k-1):
        s.append(s[0])
        s.popleft()
    print(s.popleft(), end='')
    if s:
        print(',', end='')
print('>')
        