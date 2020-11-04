import sys
input = sys.stdin.readline

brackets = list(input())

def check(bs):
    stack = []
    for b in bs:
        if b == '(' or b == '[':
            stack.append(b)
        elif b == ')' and stack:
            if stack[-1] == '(':
                stack.pop()
            else:
                stack.append(b)
        elif b == ']' and stack:
            if stack[-1] == '[':
                stack.pop()
            else:
                stack.append(b)
    if stack:
        return False
    else:
        return True

def right(bs):
    stack = []
    for b in bs:
        if b == '(' or b == '[':
            stack.append(b)
        elif b == ')':
            if stack[-1] == '(':
                stack[-1] = 2
            else:
                tmp = 0
                for i in reversed(stack):
                    if i == '(':
                        stack[-1] = tmp * 2
                        break
                    else:
                        tmp += i
                        stack.pop()
        elif b == ']':
            if stack[-1] == '[':
                stack[-1] = 3
            else:
                tmp = 0
                for i in reversed(stack):
                    if i == '[':
                        stack[-1] = tmp * 3
                        break
                    else:
                        tmp += i
                        stack.pop()
    return sum(stack)

if not check(brackets):
    print(0)
else:
    print(right(brackets))