N, M = map(int, input().split())
def dfs(n, sixcost, onecost):
    if n>=6:
        return min(onecost*6, sixcost) + dfs(n-6, sixcost, onecost)
    else:
        return min(onecost*n, sixcost)
A, B = 9999, 9999
for _ in range(M):
    a, b = map(int, input().split())
    A, B = min(A, a), min(B, b)
print(dfs(N, A, B))