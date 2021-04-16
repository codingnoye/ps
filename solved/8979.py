N, K = map(int, input().split())
d = dict()
li = [()] * N
for i in range(N):
    n, a, b, c = map(int, input().split())
    d[n] = (a, b, c)
    li[i] = (a, b, c)
li.sort(reverse=True)
for i in range(len(li)):
    c = li[i]
    if c==d[K]:
        print(i+1)
        break