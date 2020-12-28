import copy
# 벽 세워보기
def wall(idx, x, y):
    global minV
    if(idx == 3):
        temp = copy.deepcopy(check)
        qs = copy.deepcopy(q)
        a = virus(temp, qs)
        if(a < minV):
            minV = a
        return
    else:
        # 이 부분 처리를 해주지 않으면 시간초과
        ## if문을 통해 이전 재귀에서 탐색한 범위를 제외하고 for문을 수행하도록
        for i in range(x, n):
            if(i == x):
                k = y
            else:
                k = 0
            for j in range(k, m):
                if(arr[i][j] == 0 and check[i][j] == 0):
                    check[i][j] = 1
                    wall(idx+1, i, j+1)
                    check[i][j] = 0

# 바이러스 퍼뜨리기
def virus(temp, qs):
    global minV
    res = len(qs)
    while(qs):
        if(res > minV):
            return minV
        x, y = qs.pop()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if(0<=nx<n and 0<=ny<m):
                if(temp[nx][ny] == 0):
                    temp[nx][ny] = 2
                    qs.append((nx,ny))
                    res += 1
    return res
    
dx = [0,1,0,-1]
dy = [1,0,-1,-0]
n, m = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]
check = copy.deepcopy(arr)
q = []
minV = 99999
cnt = 0
# 벽의 개수와 바이러스의 위치 저장
for i in range(n):
    for j in range(m):
        if(arr[i][j] == 1):
            cnt += 1
        elif(arr[i][j] == 2):
            q.append((i,j))
wall(0,0,0)
# 안전영역의 크기는 전체크기 - 바이러스의 최소값 - 벽의개수
print(m*n - minV - cnt -3)