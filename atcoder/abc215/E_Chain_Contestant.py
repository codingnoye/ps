N = int(input())
S = input()

dp = [[1] * N for _ in range(10)]

def ctoi(c):
    return ord(c) - ord('a')

for i in range(N):
    for j in range(i+1, N):
        if S[i] == S[j]:
            dp[j] = dp[j] * (dp[i] + 1)
            dp[j] %= 998244353
        else:
            dp[j] = dp[j] + dp[i]
            dp[j] %= 998244353
print(dp)
print(dp[N-1])