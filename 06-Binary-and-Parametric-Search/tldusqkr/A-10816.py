from collections import Counter
import sys
input = sys.stdin.readline

n = int(input())
cards = list(map(int, input().split()))
m = int(input())
find = list(map(int, input().split()))

cards = Counter(cards)

for i in find:
    print(cards[i], end=' ')
