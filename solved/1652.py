N = int(input())
g = [[*map(lambda x:1 if x=='X' else 0, input())] for l in range(N)]
v, h = 0, 0
for y in range(N):
    f=0
    for x in range(N):
        if f==0 and g[y][x]==0:
            f = 1
        elif f>0 and g[y][x]==1:
            f = 0
        elif f==1 and g[y][x]==0:
            f = 2
            h += 1
for x in range(N):
    f=0
    for y in range(N):
        if f==0 and g[y][x]==0:
            f = 1
        elif f>0 and g[y][x]==1:
            f = 0
        elif f==1 and g[y][x]==0:
            f = 2
            v += 1
print(h, v)