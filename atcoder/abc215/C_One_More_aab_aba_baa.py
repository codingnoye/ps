from itertools import permutations
S, K = input().split()
C = [*S]
print(''.join(sorted({p for p in permutations(S)})[int(K)-1]))