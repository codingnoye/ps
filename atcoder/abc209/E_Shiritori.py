import sys
sys.setrecursionlimit(10**9)
input = lambda:sys.stdin.readline().rstrip()
N = int(input())
# node num are 0~N-1
sw = dict()
dp = [None] * N
parent = [i for i in range(N)]
def find(u):
    if parent[u] == u:
        return u
    parent[u] = find(parent[u])
    return parent[u]

def union(u, v):
    pu, pv = find(u), find(v)
    if pu==pv:
        return pu
    if pu<pv:
        parent[pu] = pv
    else:
        parent[pv] = pu
    return None
words = [*map(lambda x: (x[:3], x[-3:]), (input() for i in range(N)))]
for i, w in enumerate(words):
    if w[0] not in sw:
        sw[w[0]] = []
    sw[w[0]].append(i)
graph = [[] for i in range(N)]
for i, w in enumerate(words):
    if w[1] not in sw:
        continue
    for ne in sw[w[1]]:
        c = union(i, ne)
        if c is not None:
            dp[c] = 2
        graph[i].append(ne)


# 0 = lose, 1 = win, 2 = draw
def isWin(i):
    if dp[i] != None: return dp[i]
    if len(graph[i]) == 0:
        return 1
    res = 1
    for ne in graph[i]:
        iw = isWin(ne)
        if iw == 1:
            res = 0
            break
        elif iw == 2 and res == 1:
            res = 2
    dp[i] = res
    return res
# print(cycles)   
for i in range(N):
    iw = isWin(i)
    if iw==0:
        print('Aoki')
    elif iw==1:
        print('Takahashi')
    else:
        print('Draw')