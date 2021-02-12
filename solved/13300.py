N, K = map(int, input().split())
arr = [0] * 12
for _ in range(N):
    a, b = map(int, input().split())
    arr[6*a+b-1] += 1
res = 0
for i in arr:
    res += (i+K-1)//K
print(res)