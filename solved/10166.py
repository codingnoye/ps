D1, D2 = map(int, input().split())
  
dp = [i for i in range(2001)]

add = 0
res = 0
for i in range(1, D2+1):
    first = True
    for j in range(i*2, D2+1, i):
        if first and D2 >= j >= D1 and i < D1:
            add += dp[i]
            first = False
        dp[j] -= dp[i]
#print(dp)
print(sum(dp[D1:D2+1])+add)