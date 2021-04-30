A, B = map(int, input().split())
N = int(input())
now = 1
val = 0
for n in [*map(int, input().split())][::-1]:
    val += now * n
    now *= A
res = []
now = 1
while val>=now: now *= B

while now>0:
    res.append(val//now)
    val %= now
    now //= B

print(*res[1:])