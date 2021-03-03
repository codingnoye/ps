N, M = map(int, input().split())
arr = list(sorted(map(int, input().split())))

log = [0] * M
used = [False] * N

def recc(i):
    global N, M, log
    if i==M:
        print(*log)
    else:
        last = -1
        for k in range(N):
            if used[k] == False and last != arr[k]:
                used[k] = True
                log[i] = arr[k]
                last = arr[k]
                recc(i+1) 
                used[k] = False
recc(0)