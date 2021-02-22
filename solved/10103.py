a, b = 100, 100
n = int(input())
for i in range(n):
    c, d = map(int, input().split())
    if c<d: a-=d
    elif d<c: b-=c
print(a)
print(b)