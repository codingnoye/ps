S = int(input())
dp = dict()
MOD = 1000000007
def rec(s):
    if s<3: return 0
    global dp
    if s in dp: return dp[s]
    res = 1
    for i in range(3, s-3+1):
        res += rec(i)
        res %= MOD
    dp[s] = res%MOD
    return dp[s]

print(rec(S))