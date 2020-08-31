def cost(v, now):
    ai = 1
    res = 0
    for a in v:
        res += abs(ai - a)
        ai *= now
    return res

N = int(input())
v = list(map(int, input().split()))
v.sort()
mn = 100000000000001
last = mn
i = 1
while (True):
    if (i**(len(v)-1) > 100000000000000001): break
    res = cost(v, i)
    if res < mn: mn = res
    if last < res: break
    last = res
    i+=1
print(mn)