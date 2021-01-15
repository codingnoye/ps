input()
m, n, l = 0, 999999999999, 999999999999
for i in map(int, input().split()):
    if l<i:
        m = max(m, i-n)
    else:
        n = i
    l = i
print(m)