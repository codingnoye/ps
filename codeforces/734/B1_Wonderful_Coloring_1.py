import sys
input = lambda: sys.stdin.readline().rstrip()
T = int(input())
for _ in range(T):
    S = sorted([(v, i) for i, v in enumerate([*input()])])
    c = dict()
    for v, i in S:
        if v in c:
            c[v] += 1
        else:
            c[v] = 1
    jaturi = 0
    res = 0
    for k, v in c.items():
        if v < 2:
            jaturi += 1
        else:
            res += 1
    print(res + (jaturi//2))
        