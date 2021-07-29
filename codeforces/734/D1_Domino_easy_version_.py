import sys
input = lambda:sys.stdin.readline().rstrip()

T = int(input())

def make_target(coins, target, N):
    dp = [[False] * (target+1) for _ in range(N+1)]
    dp[0][0] = True
    for i in range(N):
        for j in range(target+1):
            for k in range(len(coins)):
                if j >= coins[k]:
                    dp[i+1][j] = dp[i+1][j] or dp[i][j-coins[k]]
    return dp[N][target]

for _ in range(T):
    n, m, k = map(int, input().split())
    if n%2 == 0 and m%2 == 0:
        if k%2 == 0:
            print('YES')
        else:
            print('NO')
    else:
        if m%2 == 0:
            n, m = m, n
        else:
            k = (n*m)//2 - k
        keys = [v for v in range(1, m+1, 2)]
        total = 0

        if make_target(keys, k, n//2):
            print('YES')
        else:
            print('NO')
