from decimal import *
A, B = map(int, input().split())
getcontext().prec = 1000
print(Decimal(A)/Decimal(B))