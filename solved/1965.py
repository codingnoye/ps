l=int(input())
b=[*map(int,input().split())]
d=[1]*l
for i in range(l):
 for j in range(i+1,l):
  if b[j]>b[i]:d[j]=max(d[j],d[i]+1)
print(max(d))