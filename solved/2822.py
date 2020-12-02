Q,S,N=sorted,0,[]
for s,n in Q(zip(map(int,open(0)),range(1,9)))[3:]:S,N=S+s,N+[n]
print(S)
print(*Q(N))