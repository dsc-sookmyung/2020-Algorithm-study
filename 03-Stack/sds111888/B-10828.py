import sys

input=sys.stdin.readline
n = int(input())

stack = []
point = -1

#command = ["push","pop","size","empty","top"]

for i in range(n):
    c = list(input().split())
    
    if c[0] == "push":
        c[1] = int(c[1])
        stack.append(c[1])
        point += 1
    elif c[0] == "pop":
        if point >= 0:
            print(stack[point])
            del stack[point]
            point -= 1
        else :
            print(-1)
    elif c[0] == "size":
        print((point+1))
    elif c[0] == "empty":
        if point == -1 :
            print(1)
        else :
            print(0)
    elif c[0] == "top":
        if point >= 0:
            print(stack[point])
        else :
            print(-1)