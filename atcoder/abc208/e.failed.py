N, K = map(int, input().split())

def full(acc, pow):
    if pow == -1: return 1
    if acc * (9**pow) <= K:
        return 10**pow
    res = 0
    for i in range(K):
        if acc*i <= K:
            res += full(acc*i, pow-1)
        else: break
    return res

digits = list(map(int, [*str(N)]))
p = len(str(N))-1

total = 0
def solve(acc, idx):
    now = digits[idx]
    print(digits[:idx+1])
    res = 0
    for i in range(now):
        print(f'full({acc*i}, {p-idx}) : {full(acc*i, p-idx)}')
        res += full(acc*i, p-idx)
    if idx < p:
        res += solve(acc * now, idx+1)
    return res

print(solve(1, 0) - full(0, p))