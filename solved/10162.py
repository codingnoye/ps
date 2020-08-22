x=int(input())
a=0
b=0
c=0
while a*300<=x: a+=1
a-=1
while a*300+b*60<=x: b+=1
b-=1
while a*300+b*60+c*10<=x: c+=1
c-=1
if a*300+b*60+c*10==x: print(a, b, c)
else: print(-1)