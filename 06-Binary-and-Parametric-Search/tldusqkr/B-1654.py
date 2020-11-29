import sys
input = sys.stdin.readline

k, n = map(int, input().split())
lines = []

for _ in range(k):
    lines.append(int(input()))

low, high = 1, max(lines)
result = 0

while low <= high:
    mid = (low + high) // 2
    cut_result = sum([(i // mid) for i in lines])

    if cut_result >= n:
        result = mid
        low = mid + 1
    
    else:
        high = mid - 1

print(result)