import sys
input = sys.stdin.readline

n, k, m = map(int, input().split())
l = []

for _ in range(n):
    l.append(int(input()))

left, right = 1, max(l)
result = -1

while left <= right:
    mid = (left + right ) // 2
    count = 0

    for i in range(n):
        if l[i] >= 2 * k:
            count += (l[i] - 2 * k) // mid
        elif l[i] > k:
            count += (l[i] - k) // mid
    
    if count >= m:
        result = max(result, mid)
        left = mid + 1
    else:
        right = mid - 1

print(result)
