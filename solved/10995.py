N = int(input())
for i in range(N):
    for j in range(2*N):
        if (i+j)%2 == 0:
            print("*", end='')
        else:
            print(" ", end='')
    print('')