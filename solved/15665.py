N, M = map(int, input().split())
arr = sorted(list(set(map(int, input().split()))))
L = len(arr)

log = [0] * M

def recc(i):
    global N, M, L, log
    if i==M:
        print(*log)
    else:
        for k in range(L):
            log[i] = arr[k]
            recc(i+1) 
recc(0)