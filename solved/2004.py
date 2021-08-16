n, m = map(int, input().split())
def count2(x):
    b = 2
    res = 0
    while b <= x:
        res += x // b
        b *= 2
    return res

def count5(x):
    b = 5
    res = 0
    while b <= x:
        res += x // b
        b *= 5
    return res

print(min(count2(n) - count2(m) - count2(n - m), count5(n) - count5(m) - count5(n - m)))