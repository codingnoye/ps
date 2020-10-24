from itertools import chain, combinations

def powerset(it):
    s = list(it)
    return chain.from_iterable(combinations(s, r) for r in range(len(s)+1))

N = int(input())
s = set(map(int, input().split()))
print(max(map(lambda x: max(x)+1, filter(lambda x: len(x)>0, powerset(s))))+1)