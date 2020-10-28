import sys

n = int(input())
nums = []
for i in range(n):
    nums.append(int(sys.stdin.readline()))

for j in sorted(nums):
    print(j)
