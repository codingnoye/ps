from collections import Counter
a = dict(Counter([*input()]))
b = dict(Counter([*input()]))
cnt = 0
for s in a:
    if s in b:
        cnt += abs(a[s]-b[s])
    else:
        cnt += a[s]*2
for s in b:
    if s in a:
        cnt += abs(a[s]-b[s])
    else:
        cnt += b[s]*2
print(cnt//2)