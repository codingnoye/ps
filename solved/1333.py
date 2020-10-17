N, L, D = map(int, input().split())
t = 0
for i in range(N):
    t += L
    for i in range(5):
        if t%D == 0:
            print(t)
            exit(0)
        t += 1
for i in range(D):
    if t%D == 0:
        print(t)
        exit(0)
    t += 1