people_n = int(input())
people_info = list()
for i in range(people_n):
    weight, height = map(int, input().split(' '))
    people_info.append((weight, height))

for person in people_info:
    rank = 1

    for nextPerson in people_info:
        if (person[0] != nextPerson[0]) and (person[1] != nextPerson[1]):
            if(person[0] < nextPerson[0] and person[1] < nextPerson[1]):
                rank += 1

    print(rank, end=" ")