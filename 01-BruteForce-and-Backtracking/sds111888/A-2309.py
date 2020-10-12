import sys
 
heights = []
for i in range(9):
   heights.append(int(sys.stdin.readline()))
 
sum = sum(heights)
 
finish = False

for i in range(8):
    for j in range(i + 1, 9):
        if (heights[i] + heights[j] == sum - 100):
            save = [i, j]
            finish = True
            break
 
    if (finish):
        break
 
del heights[save[0]]
del heights[save[1] - 1]
 
heights.sort()
 
for i in heights:
    print(i)
