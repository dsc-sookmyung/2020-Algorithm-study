import sys

n, k = map(int, sys.stdin.readline().split())
arr = sys.stdin.readline().split()

if arr.count('1') < k:
    print(-1)
else:
    lion = [i for i, x in enumerate(arr) if x == '1']
    print(min(lion[k-1+j] - lion[j] + 1 for j in range(len(lion)-k+1)))