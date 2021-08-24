N = int(input())
price = [0] + [*map(int, input().split())]
dp = [0] * (N + 1)
dp[0] = 0
for i in range(1, N + 1):
    dp[i] = price[i]
    for j in range(1, i+1):
        dp[i] = min(dp[i], dp[i-j] + price[j])
print(dp[N])