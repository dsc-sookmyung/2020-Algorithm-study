import sys

stack = list()
top = len(stack)-1

def push(num):
    stack.append(num)
def pop():
    try:
        print(stack.pop())
    except:
        print(-1)
def size():
    return(len(stack))
def empty():
    result = 1 if size() == 0 else 0
    return result
def top():
    try:
        print(stack[-1])
    except:
        print(-1)

N = int(sys.stdin.readline())

for _ in range(N):
    cmd = sys.stdin.readline().split()
    if cmd[0] == 'push':
        push(cmd[1])
    elif cmd[0] == 'pop':
        pop()
    elif cmd[0] == 'empty':
        print(empty())
    elif cmd[0] == 'size':
        print(size())
    elif cmd[0] == 'top':
        top()


