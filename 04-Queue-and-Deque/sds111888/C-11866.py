from collections import deque

n, k = map(int, input().split())
arr = deque()

for i in range(1, n + 1):
    arr.append(i)

print('<', end='')
while arr:
    for i in range(k - 1):
        arr.append(arr[0])
        arr.popleft()
    print(arr.popleft(), end='')
    if arr:
        print(', ', end='')
print('>')