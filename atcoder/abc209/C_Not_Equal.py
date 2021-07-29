N = int(input())
C = sorted(list(map(int, input().split())))
sub = 0
cum = 1
MOD = 1000000007
for c in C:
    if c-sub<=0:
        cum = 0
        break
    cum *= c-sub
    cum %= MOD
    sub += 1
print(cum)