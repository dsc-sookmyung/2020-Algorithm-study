def check(index):
    s = 0
    for i in range(index, -1, -1):
        s += ans[i]
        if sign[i][index] == 0:
            if s != 0:
                return False
        elif sign[i][index] < 0:
            if s >= 0:
                return False
        elif sign[i][index] > 0:
            if s <= 0:
                return False
    return True


def solve(index): 
    if index == n: 
        return True
    if sign[index][index] == 0:
        ans[index] = 0
        return check(index) and solve(index + 1) 
    for i in range(1, 11):
        ans[index] = i * sign[index][index]
        if check(index) and solve(index + 1):
            return True
    return False


n = int(input())
ans = [0] * n
signs = list(input())
sign = [[0 for _ in range(n)] for _ in range(n)]

idx = 0

for i in range(0, n):
    for j in range(i, n):
        if signs[idx] == '+':
            sign[i][j] = 1
        elif signs[idx] == '-':
            sign[i][j] = -1
        idx += 1

solve(0)
print(' '.join(map(str, ans)))
