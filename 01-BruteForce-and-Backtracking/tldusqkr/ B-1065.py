num = int(input())
han = 0

for i in range(1, num+1):
   if i <= 99:
       han += 1
   else:
       numArr = list(map(int, list(str(i))))
       if numArr[0] - numArr[1] == numArr[1] - numArr[2]:
           han += 1

print(han)