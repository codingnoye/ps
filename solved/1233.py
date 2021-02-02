from collections import Counter as X
A,B,C=map(int,input().split())
Z=X(a+b+c for a in range(A)for b in range(B)for c in range(C))
print(max(Z,key=lambda x:(Z[x],-x))+3)