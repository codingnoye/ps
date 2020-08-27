N = int(input())
nxt = [
    [0, 3, 2],
    [3, 0, 1],
    [2, 1, 0],
]
def call(n, now, dest):
    global nxt
    if n==1:
        print(now, dest)
        return
    call(n-1, now, nxt[now-1][dest-1])
    print(now, dest)
    call(n-1, nxt[now-1][dest-1], dest)
print(2**N-1)
call(N, 1, 3)