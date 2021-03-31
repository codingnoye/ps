st = input() + 'x'
zeros, ones = 0, 0
now = -1
for c in st:
    if now == 0:
        if c == '0':
            continue
        else:
            zeros += 1
            now = 1
    elif now == 1:
        if c == '1':
            continue
        else:
            ones += 1
            now = 0
    else:
        if c=='0':
            now = 0
        else:
            now = 1
print(min(ones, zeros))