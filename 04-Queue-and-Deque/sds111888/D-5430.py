for i in range(int(input())):
    n = input()
    arrLen = int(input())
    if(arrLen == 0):
        arr = input()
        arr = []
    else:
        arr = list(map(int, input()[1:-1].split(',')))
    isReversed = False
    isOk = True
    front = 0
    rear = 0
    
    for act in n:
        try:
            if(act == 'R'):
                isReversed = not isReversed
            elif(act == 'D' and not isReversed):
                front += 1
            elif(act == 'D' and isReversed):
                rear += 1
        except:
            isOk = False
            print('error')
            break

    if(isOk):
        if(front + rear <= arrLen):
            if(not isReversed):
                arr = arr[front:arrLen - rear]
                print(str(arr).replace(' ', ''))
            else:
                arr = arr[::-1][rear:arrLen - front]
                print(str(arr).replace(' ', ''))
        else:
            print('error')