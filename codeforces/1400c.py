T = int(input())
for _ in range(T):
    S = input()
    N = int(input())
    L = len(S)
    arr = [0]*L
    iszero = [False]*L
    for i in range(L):
        if (S[i] == '0'):
            if (i-N >= 0): iszero[i-N] = True
            if (i+N < L): iszero[i+N] = True
    used = False
    for i in range(L):
        if (S[i] == '1'):
            used = False
            if (i-N>=0):
                if (not iszero[i-N]):
                    used = True
                    arr[i-N] = 1    
            if (i+N<L):
                if (not iszero[i+N]):
                    used = True
                    arr[i+N] = 1
            if (not used):
                print(-1)
                break
    else:
        for i in range(L):
            print(arr[i], end='')
        print('')