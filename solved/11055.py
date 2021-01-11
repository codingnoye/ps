N, B = map(int, input().split())
T = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'
i = 1
res = ''
while N>0:
    N, M = divmod(N, B)
    res = T[M] + res
print(res)