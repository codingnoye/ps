import random
input()
A = list(enumerate(map(int, input().split())))

candi = sorted(A, key=lambda x: x[1])[:100]
while True:
    i, now = random.choice(A)
    for (j, x) in candi:
        if i == j:
            continue
        elif now % x == 0:
            print(j+1, i+1)
            exit(0)