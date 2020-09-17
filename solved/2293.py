N,K=map(int,input().split())
I=eval('int(input()),'*N)
dp=[1]+[0]*K
for c in I:
 for i in range(c,K+1):
  dp[i]+=dp[i-c]
print(dp[K])