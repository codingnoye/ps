import sys
input = lambda: sys.stdin.readline().strip()
def tri(n):
    return (n*(n+1))//2
for _ in range(int(input())):
    N = int(input())
    found = False
    for a in range(1, 45):
        for b in range(a, 45):
            for c in range(b, 45):
                if tri(a)+tri(b)+tri(c) == N:
                    found = True
                elif tri(a)+tri(b)+tri(c) > N:
                    break
            if tri(a)+tri(b) >= N: break
        if tri(a) >= N: break
    print(1 if found else 0)