a=lambda x:sum(map(lambda y:int(str(y),16),x))
def c(x):
 q='0123456789ab'
 w,e=divmod(x,12)
 return q[e]+(c(w)if w else'')
for i in range(1000,10000):
 if eval(f'{a(str(i))}=={a(c(i))}=={a(hex(i)[2:])}'):
     print(i)