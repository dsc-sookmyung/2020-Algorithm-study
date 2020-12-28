import sys
sys.setrecursionlimit(10000)

def dfs(X, Y):
    global MAP, M, N
    dx, dy = [-1, 0, 1, 0], [0, -1, 0, 1]
    MAP[X][Y] = -1
    for i in range(4):
        XX, YY = X + dx[i], Y + dy[i]
        if XX < 0 or XX == M or YY < 0 or YY == N:
            continue
        if MAP[XX][YY] == 1:
            MAP[XX][YY] = -1
            dfs(XX, YY)

T = int(input())
for _ in range(T):
    M, N, K = map(int, input().split())
    MAP = [[0]*N for _ in range(M)]
    count = 0
    for _ in range(K):   
        X, Y = map(int, input().split())
        MAP[X][Y] = 1
    for i in range(M):
        for j in range(N):
            if MAP[i][j] > 0:
                dfs(i, j)
                count += 1
    print(count)