heights =[]
for i in range(9):
    heights.append(int(input()))

total = sum(heights)

find = False

for i in range(9):
    for j in range(i+1, 9):
        if (heights[i]+heights[j] == total-100):
            fake = [i, j]
            find = True
            break
    
    if(find):
        break

del heights[fake[1]]
del heights[fake[0]]

heights.sort()

for i in heights:
    print(i)