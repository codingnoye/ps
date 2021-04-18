a,b,c,d,e = map(int,input().split())
p = lambda:print(a,b,c,d,e)
while (a,b,c,d,e) != (1,2,3,4,5):
    if a>b:
        a,b = b,a
        p()
    if b>c:
        b,c = c,b
        p()
    if c>d:
        c,d = d,c
        p()
    if d>e:
        d,e = e,d
        p()
    