N,K=map(int,input().split())
A=[*map(int,input().split())]
C=[0]*(N+1)
for i in range(N):C[i+1]=C[i]+A[i]
print(max(C[i+K]-C[i]for i in range(N-K+1)))