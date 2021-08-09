r,s,d=0,0,{0:1}
x,y=open(0)
for n in y.split():s+=int(n);r+=d.get(s-int(x.split()[1]),0);d[s]=d.get(s,0)+1
print(r)