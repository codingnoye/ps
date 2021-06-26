A, B, C, D = map(int, input().split())
if C*D <= B:
    print(-1)
    exit(0)
r, b, c = 0, A, 0
while r*D<b:
    r, b = r+C, b+B
    c += 1
print(c)