import sys
from decimal import Decimal
input = lambda:sys.stdin.readline().rstrip()
N = int(input())
arr = [Decimal(input()) for _ in range(N)]
now = 1
mx = 0
for i in range(N):
    now = max(arr[i], now * arr[i])
    mx = max(mx, now)
print(round(mx, 3))