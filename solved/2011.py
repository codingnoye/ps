S = input()  
N = len(S)
dp = [0] * (N+1)
dp[N-1] = 1 if S[-1]!='0' else 0
dp[N] = 1
def valid(s):
    ints = int(s)
    return ints>9 and ints<27
for i in range(N-2, -1, -1):
    if valid(S[i:i+2]): dp[i] = dp[i+2] + dp[i+1]
    elif int(S[i])==0: dp[i] = 0
    else: dp[i] = dp[i+1]
    dp[i] %= 1000000
print(dp[0])