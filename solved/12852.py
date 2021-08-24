N = int(input())
dp = [(987654321, 0) for _ in range(3*N+1)]

dp[1] = (0, 0)
for i in range(1, N+1):
    if dp[i+1][0] > dp[i][0]+1:
        dp[i+1] = (dp[i][0]+1, i)
    if dp[i*2][0] > dp[i][0]+1:
        dp[i*2] = (dp[i][0]+1, i)
    if dp[i*3][0] > dp[i][0]+1:
        dp[i*3] = (dp[i][0]+1, i)

now = N
res = []
while now > 0:
    dist, frm = dp[now]
    res += [now]
    now = frm    
print(len(res)-1)
print(*res)