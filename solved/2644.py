from collections import deque
conn = [[False] * 101 for _ in range(101)]
visited = [False] * 101
N = int(input())
A, B = map(int, input().split())
M = int(input())
for _ in range(M):
    a, b = map(int, input().split())
    conn[a][b] = True
    conn[b][a] = True

q = deque()
q.append([A, 0])
while len(q):
    now, d = q.popleft()
    if now==B:
        print(d)
        break
    visited[now] = True
    for i in range(1, N+1):
        if conn[now][i] and not visited[i]:
            q.append([i, d+1])
else: print(-1)