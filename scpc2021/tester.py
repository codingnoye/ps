import random

T = 1
N = random.randint(1, 5)
K = random.randint(1, N)
A = [random.randint(-4, 4) for _ in range(N)]

with open('res', 'w') as f:
    f.write(f'{T}\n{N} {K}\n')
    for a in A:
        f.write(f'{a} ')
    f.close()

print(f'{T}')
print(f'{N} {K}')
print(f'{" ".join(map(str, A))}')