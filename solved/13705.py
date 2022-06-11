from decimal import *
getcontext().prec = 30

pi = Decimal('3.1415926535897932384626433')

def sin(x):
    x = x % (2 * pi)
    getcontext().prec += 2
    i, lasts, s, fact, num, sign = 1, 0, x, 1, x, 1
    while s != lasts:
        lasts = s
        i += 2
        fact *= i * (i - 1)
        num *= x * x
        sign *= -1
        s += num / fact * sign
    getcontext().prec -= 2
    return +s

A, B, C = map(Decimal, input().split())

def f(x):
    return A*x + B*sin(x) - C

eps = Decimal('0.000000000000000000000001')
l, r = (C-B) / A, (C+B) / A
while l + eps < r:
    m = (l+r)/2
    v = f(m)
    if v > 0:
        r = m
    else:
        l = m
print(f'{l:.6f}')