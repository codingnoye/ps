input()
arr = list(map(int, input().split()))
def gcd(a, b):
    if b==0: return a
    return gcd(b, a%b)
for n in arr[1:]:
    g = gcd(n, arr[0])
    print(f'{arr[0]//g}/{n//g}')