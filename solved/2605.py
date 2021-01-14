input()
r = []
for i, n in enumerate(map(int,input().split())):
    if n==0: r = r + [i+1]
    else: r = r[:-n] + [i+1] + r[-n:]
print(*r)