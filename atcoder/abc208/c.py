N, K = map(int, input().split())
arr = list(map(int, input().split()))
pair = [(originV, i) for i, originV in enumerate(sorted(arr))]
dt = dict(pair)
dv = K // N
md = K % N

for item in arr:
    print(dv+1 if dt[item] < md else dv)