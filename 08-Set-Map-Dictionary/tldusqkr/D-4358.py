import sys
input = sys.stdin.readline

def getProb(T, t):
    return t / T * 100

data = input().split('\n')
dic = {}
T = 0
for d in data: 
    if d != '':
        T += 1
        if d not in dic.keys():
            dic[d] = 1
        else:
            dic[d] += 1

result = sorted(dic.items())

for t in result:
    print("%s %.4f" % (t[0], getProb(T, t[1])))