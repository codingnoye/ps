import math
f = [math.factorial(i) for i in range(11)]
def dfs(val, cnt):
    mn = 99999999
    for i in range(1, 11):
        if val < f[i]:
            break
        mn = min(dfs(val - f[i], cnt+1))
    return 