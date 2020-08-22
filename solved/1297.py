C, a, b = map(int, input().split())
c = (a**2+b**2)**.5
ratio = C/c
print(int(a*ratio), int(b*ratio))