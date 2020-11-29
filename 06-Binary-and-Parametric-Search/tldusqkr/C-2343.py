import sys
input = sys.stdin.readline

n, m = map(int, input().split())
minutes = list(map(int, input().split()))

low, high = max(minutes), sum(minutes)

while low <= high:
    mid = (low + high) // 2

    count = 0
    play_min = 0
    
    for lesson in minutes:
        if lesson + play_min > mid:
            count += 1
            play_min = 0

        play_min += lesson

    count += 1 if play_min else 0

    if count <= m:
        high = mid -1
    else:
        low = mid + 1
print(low)