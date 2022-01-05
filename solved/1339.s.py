m,a,r=[0]*99,9,0
for i in[1]*int(input()):
 for c in input()[::-1]:m[ord(c)]-=i;i*=10
for i in sorted(m):r-=i*a;a-=1
print(r)