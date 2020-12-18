s = 1
res = 0
input()
for c in input().split():
    if c=='1':
        res += s
        s += 1
    else:
        s = 1
print(res)