input()
d = dict()
for i in map(int, input().split()):
    if i in d: d[i]+=1
    else: d[i] = 1
input()
for i in map(int, input().split()):
    if i in d: print(d[i], end=' ')
    else: print(0, end=' ')