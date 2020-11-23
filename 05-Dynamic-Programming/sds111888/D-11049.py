# PyPy3

import sys
input = sys.stdin.readline

n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]
dp = [[0 for _ in range(n)] for _ in range(n)] 

for i in range(1, n):
    for j in range(n - i):
        x = j + i
        dp[j][x] = 2 ** 32
        for k in range(j, x):
            dp[j][x] = min(dp[j][x], dp[j][k] + dp[k + 1][x] + arr[j][0] * arr[k][1] * arr[x][1])

answer = dp[0][n-1]
print(answer)