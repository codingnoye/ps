N = int(input())
N2 = 2*N
res = 0
for i in range(1, int(N2**.5)+1):
    if N2%i != 0: continue
    a, b = i, N2//i
    if a%2 + b%2 == 1:
        res += 1
print(res*2)