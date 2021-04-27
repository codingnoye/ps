N,T=map(int,input().split())
for i,c in enumerate(input().split()):
 T-=int(c)
 if T<0:
  print(i)
  exit(0)
print(N)