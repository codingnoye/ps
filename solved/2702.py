def gcd(a, b):
    if b==0: return a
    else: return gcd(b, a%b)
for _ in range(int(input())):
    a, b = map(int, input().split())
    print(a*b//gcd(a, b), gcd(a, b))