a, b = input().split()

mn = 999999999
for bs in range(len(b)-len(a)+1):
    bsub = b[bs:bs+len(a)]
    dist = 0
    for i in range(min(len(a), len(bsub))):
        if a[i] != bsub[i]:
            dist += 1
    mn = min(mn, dist)
    
print(mn)