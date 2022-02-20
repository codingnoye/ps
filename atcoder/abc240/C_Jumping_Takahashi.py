N, X = map(int, input().split())
can = {0}
for i in range(N):
    newcan = set()
    a, b = map(int, input().split())
    for x in can:
        if x+a <= X:
            newcan.add(x+a)
        if x+b <= X:
            newcan.add(x+b)
    can = newcan
if X in can:
    print("Yes")
else:
    print("No")