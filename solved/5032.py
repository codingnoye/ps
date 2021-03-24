a,b,c=map(int,input().split())
def rc(d,c):
 if d<c:return 0
 return d//c+rc(d%c+d//c,c)
print(rc(a+b,c))