l,r=0,0
for i in[*open(0)][:0:-1]:r+=l<int(i);l=max(l,int(i))
print(r)