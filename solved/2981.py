def gcd(a, b):
    while b:
        a,b = b,a%b
    return a
N = int(input())
li = [int(input()) for _ in range(N)]
mli = min(li)
nowgcd = gcd(li[0]-mli, li[1]-mli)
for i in range(1, len(li)-1):
    nowgcd = gcd(nowgcd, li[i+1]-mli)
for i in range(2, nowgcd+1):
    if nowgcd%i==0: print(i, end=' ')