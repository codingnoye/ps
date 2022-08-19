r1, r2, r3, r4, r5 = 0, 0, 0, 0, 0
for l in [*open(0)][1:]:
    a, b = map(int, l.split())
    if a>0 and b>0:
        r1 += 1
    elif a<0 and b>0:
        r2 += 1
    elif a<0 and b<0:
        r3 += 1
    elif a>0 and b<0:
        r4 += 1
    else:
        r5 += 1
print(f'Q1: {r1}')
print(f'Q2: {r2}')
print(f'Q3: {r3}')
print(f'Q4: {r4}')
print(f'AXIS: {r5}')