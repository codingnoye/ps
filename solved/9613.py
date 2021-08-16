def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

T = int(input())
for _ in range(T):
    arr = list(map(int, input().split()))[1:]
    res = 0
    for i in range(len(arr)):
        for j in range(i + 1, len(arr)):
            res += gcd(arr[i], arr[j])
    print(res)