N,m=int(input()),0
R=sorted(eval('int(input()),'*N))
for i in range(N):m=max(R[i]*(N-i),m)
print(m)