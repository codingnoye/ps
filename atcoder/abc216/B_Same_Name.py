N = int(input())
d = set()
for i in range(N):
    S = input()
    if S in d:
        print('Yes')
        exit(0)
    d.add(S)
print('No')