MOD = 1000000007

def fpow(x, n):
    e = 1
    while n > 1:
        if n & 1: e = (e*x) % MOD
        x = (x*x) % MOD
        n >>=1
    return (x*e)%MOD

N = int(input())
print((fpow(10, N) - 2*fpow(9, N) + fpow(8, N))%MOD)