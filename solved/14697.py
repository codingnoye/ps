a,b,c,d=map(int,input().split())
for i in range(d//a+1):
    for j in range(d//b+1):
        if i*a+j*b>d: break
        for k in range(d//b+1):
            if i*a+j*b+k*c>d: break
            if i*a+j*b+k*c==d:
                print(1)
                exit(0)
print(0)