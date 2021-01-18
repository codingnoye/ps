l=[*map(int,open(0))]
s,e,r=sum(l)-100,len(l),range
for i in r(e):
 for j in r(i+1,e):
  if l[i]+l[j]==s:
   for k in r(e):
    if k!=i and k!=j:print(l[k])