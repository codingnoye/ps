i = [*open(0)]
total = int(i[0])
sm = 0
for l in i[2:]:
    a, b = map(int, l.split())
    sm += a*b
print('Yes' if sm == total else 'No')