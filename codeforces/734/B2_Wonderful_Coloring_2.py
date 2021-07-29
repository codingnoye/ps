import sys
input = lambda: sys.stdin.readline().rstrip()
T = int(input())
for t in range(T):
    N, K = map(int, input().split())
    arr = sorted([(v, i)for i, v in enumerate(map(int, input().split()))])

    lasts = [-1] * len(arr)
    res = [0] * len(arr)

    d = dict()
    for v, i in arr:
        if v not in d:
            d[v] = 0
        else:
            d[v] += 1
    
    arr_overK = []
    arr_underK = []
    for v, i in arr:
        if d[v] >= K:
            arr_overK.append((v, i))
        else:
            arr_underK.append((v, i))
    
    last = -1
    k = 0
    for v, i in arr_overK:
        if v != last:
            k = 0
        if k>=K:
            pass
        else:
            res[i] = k+1
            k += 1
        last = v
    
    k = 0
    for i in range(len(arr_underK) - len(arr_underK)%K):
        v, i = arr_underK[i]
        res[i] = k+1
        k += 1
        k %= K

    print(*res)
