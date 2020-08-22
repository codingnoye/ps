N = int(input())
arr = [list(map(int, input())) for _ in range(N)]
visited = [[False]*N for _ in range(N)]

def dfs(y, x):
    if y<0 or y>=N or x<0 or x>=N: return 0
    if arr[y][x] == 0: return 0
    if visited[y][x]: return 0
    visited[y][x] = True
    return 1 + dfs(y-1, x) + dfs(y+1, x) + dfs(y, x-1) + dfs(y, x+1)

danzis = []

for y in range(N):
    for x in range(N):
        if not visited[y][x] and arr[y][x] == 1:
            danzis.append(dfs(y, x))
print(len(danzis))
for danzi in sorted(danzis):
    print(danzi)