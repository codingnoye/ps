import sys
from collections import deque
input = sys.stdin.readline
N, M = map(int, input().split())
visited = [[False]*N for _ in range(M)]
arr = [[0]*N for _ in range(M)]
Q = deque()
for m in range(M):
    tmp = list(map(int, input().split()))
    for n in range(N):
        arr[m][n] = tmp[n]
        if tmp[n] == 1:
            Q.append((m, n, 1))

while len(Q):
    y, x, i = Q.popleft()
    if y<0 or y>=M or x<0 or x>=N: continue
    if visited[y][x]: continue
    if arr[y][x] == -1: continue
    visited[y][x] = True
    arr[y][x] = i
    Q.append((y-1, x, i+1))
    Q.append((y+1, x, i+1))
    Q.append((y, x-1, i+1))
    Q.append((y, x+1, i+1))
mx = 0
for y in range(M):
    for x in range(N):
        if arr[y][x]==0:
            print(-1)
            exit(0)
        mx = max(mx, arr[y][x])
print(max(mx-1, 0))