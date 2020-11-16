#pypy3 
n, k = map(int, input().split())

a = [0] * 1000001

for i in range(n):
    b, c = map(int, input().split())
    a[c] = b

k = k * 2 + 1
s = 0
ans = 0

for i in range(0, 1000001):
    if i >= k:
        s -= a[i-k]
    s += a[i]
    if s > ans:
        ans = s
print(ans)
