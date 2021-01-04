import sys

N, M = map(int, input().split())
number = 1
pokemon1 = {}
pokemon2 = {}

for _ in range(N):
    name = str(sys.stdin.readline()).strip()
    pokemon1[number] = name
    pokemon2[name] = number
    number += 1

answer = []
for _ in range(M):
    pokemon = str(sys.stdin.readline()).strip()
    try:
        print(pokemon1[int(pokemon)])
    except:
        print(pokemon2[pokemon])