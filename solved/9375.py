from collections import Counter
for _ in range(int(input())):
    c = Counter()
    for i in range(int(input())):
        x, e = input().split()
        c.update([e])
    res = 1
    for i in c.values():
        res *= i+1
    print(res-1)