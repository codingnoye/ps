input()
s = list(map(int,input().split()))
a,b = 0,0
for c in s:
    a += ((c+30)//30)*10
    b += ((c+60)//60)*15
if a<b: print('Y', a)
elif b<a: print('M', b)
else: print('Y', 'M', a)