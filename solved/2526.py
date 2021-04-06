N, P = map(int, input().split())
v = dict()
now = 1
nowi = 0
while True:
    if now in v:
        print(nowi - v[now])
        break
    v[now] = nowi
    nowi += 1
    now = (now * N)%P