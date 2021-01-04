import sys
input = sys.stdin.readline
people = {}
cnt = 0

def getTime(x):
    h, m = map(int, x.split(':'))
    return h * 60 + m

s, e, q = input().split(' ')
S = getTime(s)
E = getTime(e)
Q = getTime(q)

for line in sys.stdin:
    time, id = line.strip().split(' ')
    time = getTime(time)
    id = str(id)
    if time <= S:
        people[id] = 1
    elif Q >= time >= E:
        if people.get(id) and people[id] == 1:
            cnt += 1
            people[id] = 0

print(cnt)