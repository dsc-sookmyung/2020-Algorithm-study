N = int(input())

people = []

for _ in range(N):
    w, h = map(int, input().split())
    people.append((w, h))

for c in people : 
    rank = 1 
    
    for n in people:
        if (c[0]!=n[0]) & (c[1]!=n[1]):
            if (c[0]<n[0]) & (c[1]<n[1]):
                rank += 1
            
    print(rank)