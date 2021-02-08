S = set()
for i in range(int(input())):
    name, c = input().split()
    if c=='enter': S.add(name)
    else: S.remove(name)
for name in sorted(S, reverse=True): print(name)