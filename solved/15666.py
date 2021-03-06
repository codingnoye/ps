N, M = map(int, input().split())
arr = sorted(list(set(map(int, input().split()))))
L = len(arr)

log = [0] * M

def recc(i, s):
    global N, M, L, log
    if i==M:
        print(*log)
    else:
        for k in range(s, L):
            log[i] = arr[k]
            recc(i+1, k) 
recc(0, 0)