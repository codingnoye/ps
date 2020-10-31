N, M, K = map(int, input().split())
while K>0:
    if M*2 > N:
        M -= 1
    else:
        N -= 1
    K -= 1
if M<=0 or N<=0: print(0)
else: print(min(N//2, M))