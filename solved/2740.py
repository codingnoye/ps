A, X = map(int, input().split())
MA = [[*map(int, input().split())] for _ in range(A)]
X, B = map(int, input().split())
MB = [[*map(int, input().split())] for _ in range(X)]

res = [[0] * B for _ in range(A)]
for a in range(A):
    for b in range(B):
        for x in range(X):
            res[a][b] += MA[a][x] * MB[x][b]
for a in range(A):
    print(*res[a])