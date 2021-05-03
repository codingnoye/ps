N = int(input())
ban = [[set() for _ in range(10)] for _ in range(5)]
inp = []
for st in range(N):
    inp.append([*map(int, input().split())])
    for i in range(5):
        ban[i][inp[st][i]].add(st)
res = []
for st in range(N):
    fr = set()
    for i in range(5):
        fr |= ban[i][inp[st][i]]
    res.append((len(fr), st))
print(max(res, key=lambda r:(r[0], -r[1]))[1]+1)