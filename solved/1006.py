INF = 4000000

def case0(N, W, arr):
    # case 0: no link
    full = [0] * (N+3)
    upper = [0] * (N+3)
    lower = [0] * (N+3)

    full[0] = 1 if arr[0][0] + arr[0][1] <= W else 2
    upper[0] = 1
    lower[0] = 1
    for i in range(1, N):
        full[i] = full[i-1] + (1 if arr[i][0] + arr[i][1] <= W else 2)
        if arr[i][0]+arr[i-1][0]<=W:
            full[i] = min(full[i], lower[i-1] + 2)
        if arr[i][1]+arr[i-1][1]<=W:
            full[i] = min(full[i], upper[i-1] + 2)
        if arr[i][0]+arr[i-1][0]<=W and arr[i][1]+arr[i-1][1]<=W:
            full[i] = min(full[i], full[i-2] + 2)

        upper[i] = full[i-1] + 1
        if arr[i][0]+arr[i-1][0]<=W:
            upper[i] = min(upper[i], lower[i-1] + 1)

        lower[i] = full[i-1] + 1
        if arr[i][1]+arr[i-1][1]<=W:
            lower[i] = min(lower[i], upper[i-1] + 1)
        
    return full[N-1]

def case1(N, W, arr):
    # case 1: link at upper
    full = [0] * (N+3)
    upper = [0] * (N+3)
    lower = [0] * (N+3)
    if arr[0][0]+arr[-1][0]>W: return INF
    full[0] = 2
    full[-1] = INF
    upper[0] = 1
    lower[0] = INF
    lower[-1] = INF
    for i in range(1, N):
        full[i] = full[i-1] + (1 if arr[i][0] + arr[i][1] <= W else 2)
        if arr[i][0]+arr[i-1][0]<=W:
            full[i] = min(full[i], lower[i-1] + 2)
        if arr[i][1]+arr[i-1][1]<=W:
            full[i] = min(full[i], upper[i-1] + 2)
        if arr[i][0]+arr[i-1][0]<=W and arr[i][1]+arr[i-1][1]<=W:
            full[i] = min(full[i], full[i-2] + 2)

        upper[i] = full[i-1] + 1
        if arr[i][0]+arr[i-1][0]<=W:
            upper[i] = min(upper[i], lower[i-1] + 1)

        lower[i] = full[i-1] + 1
        if arr[i][1]+arr[i-1][1]<=W:
            lower[i] = min(lower[i], upper[i-1] + 1)
        
    return lower[N-1]

def case2(N, W, arr):
    # case 2: link at lower
    full = [0] * (N+3)
    upper = [0] * (N+3)
    lower = [0] * (N+3)
    if arr[0][1]+arr[-1][1]>W: return INF
    full[0] = 2
    full[-1] = INF
    upper[0] = INF
    upper[-1] = INF
    lower[0] = 1
    for i in range(1, N):
        full[i] = full[i-1] + (1 if arr[i][0] + arr[i][1] <= W else 2)
        if arr[i][0]+arr[i-1][0]<=W:
            full[i] = min(full[i], lower[i-1] + 2)
        if arr[i][1]+arr[i-1][1]<=W:
            full[i] = min(full[i], upper[i-1] + 2)
        if arr[i][0]+arr[i-1][0]<=W and arr[i][1]+arr[i-1][1]<=W:
            full[i] = min(full[i], full[i-2] + 2)

        upper[i] = full[i-1] + 1
        if arr[i][0]+arr[i-1][0]<=W:
            upper[i] = min(upper[i], lower[i-1] + 1)

        lower[i] = full[i-1] + 1
        if arr[i][1]+arr[i-1][1]<=W:
            lower[i] = min(lower[i], upper[i-1] + 1)
        
    return upper[N-1]

def case3(N, W, arr):
    # case 3: link at both
    full = [0] * (N+1)
    upper = [0] * (N+1)
    lower = [0] * (N+1)
    if arr[0][1]+arr[-1][1]>W: return INF
    if arr[0][0]+arr[-1][0]>W: return INF
    full[0] = 2
    full[-1] = INF
    upper[0] = INF
    upper[-1] = INF
    lower[0] = INF
    lower[-1] = INF
    for i in range(1, N-1):
        full[i] = full[i-1] + (1 if arr[i][0] + arr[i][1] <= W else 2)
        if arr[i][0]+arr[i-1][0]<=W:
            full[i] = min(full[i], lower[i-1] + 2)
        if arr[i][1]+arr[i-1][1]<=W:
            full[i] = min(full[i], upper[i-1] + 2)
        if arr[i][0]+arr[i-1][0]<=W and arr[i][1]+arr[i-1][1]<=W:
            full[i] = min(full[i], full[i-2] + 2)

        upper[i] = full[i-1] + 1
        if arr[i][0]+arr[i-1][0]<=W:
            upper[i] = min(upper[i], lower[i-1] + 1)

        lower[i] = full[i-1] + 1
        if arr[i][1]+arr[i-1][1]<=W:
            lower[i] = min(lower[i], upper[i-1] + 1)
        
    return full[N-2]


T = int(input())
for _ in range(T):
    N, W = map(int, input().split())
    arr = list(zip(list(map(int, input().split())), list(map(int, input().split()))))
    if N==1:
        print(1 if arr[0][0] + arr[0][1] <= W else 2)
        continue
    #print((case0(N, W, arr), case1(N, W, arr), case2(N, W, arr), case3(N, W, arr)))
    print(min(case0(N, W, arr), case1(N, W, arr), case2(N, W, arr), case3(N, W, arr)))