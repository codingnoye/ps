last = -1
res = 0
for N in [*map(int,open(0))][:0:-1]:
    if last!=-1 and N>=last:
        res += N-last+1
        last = last-1
    else: last = N
print(res)