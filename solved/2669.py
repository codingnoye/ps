o={0}
for a in open(0):
 q,w,e,r=map(int,a.split())
 o|={(x,y)for x in range(q,e)for y in range(w,r)}
print(len(o)-1)