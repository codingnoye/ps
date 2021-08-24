import sys
input = lambda:sys.stdin.readline().rstrip()
print = lambda x:sys.stdout.write(str(x)+'\n')

sieve = [False] * 100001
sieve2 = [False] * 100001
sosus = [None] * 50001
sosulen = 0

N, M = map(int, input().split())
arr = list(map(int, input().split()))

def gcd(a, b):
    if b == 0: return a
    return gcd(b, a % b)

def lcm(a, b):
    return a * b // gcd(a, b)

for i in range(2, 100001):
    if sieve[i] == False:
        sosus[sosulen] = i
        sosulen += 1
        for j in range(i + i, 100001, i):
            sieve[j] = True

l = arr[0]
for i in range(1, N):
    l = lcm(l, arr[i])

for i in range(sosulen):
    sosu = sosus[i]
    if l % sosu == 0:
        if sieve2[sosu] == False:
            for j in range(sosu, 100001, sosu):
                sieve2[j] = True
    if l < sosu:
        break

res = [None] * M
reslen = 0
for i in range(1, M+1):
    if sieve2[i] == False:
        res[reslen] = i
        reslen += 1
print(reslen)
for i in range(reslen):
    print(res[i])