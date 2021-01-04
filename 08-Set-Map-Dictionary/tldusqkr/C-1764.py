import sys
input = sys.stdin.readline

N, M = map(int, input().split())
N_list = [input().strip() for _ in range(N)]
M_list = [input().strip() for _ in range(M)]

duplicate = list(set(N_list) & set(M_list))

print(len(duplicate))
for name in sorted(duplicate):
    print(name)