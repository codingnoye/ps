n = int(input())
now = 1
for i in range(n):
    a, b = map(int, input().split())
    if a==now: now=b
    elif b==now: now=a
print(now)