A, P = map(int, input().split())
now = A
v = dict()
i = 0
while True:
    if now in v:
        print(i - (i - v[now]))
        break
    v[now] = i
    now = sum(map(lambda x:int(x)**P, str(now)))
    i += 1