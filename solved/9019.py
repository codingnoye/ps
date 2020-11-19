from collections import deque
import sys
T = int(sys.stdin.readline())
for _ in range(T):
    a, b = map(int, sys.stdin.readline().split())
    visited = [False] * 10000
    Q = deque()
    Q.append([a, "", None])
    while len(Q)>0:
        now = Q.popleft()
        if visited[now[0]]: continue
        visited[now[0]] = True
        if now[0] == b:
            tmp = now
            res = ''
            while tmp[2] != None:
                res = tmp[1] + res
                tmp = tmp[2]
            sys.stdout.write(str(res)+'\n')
            break
        D = Q.append([(now[0]*2)%10000, 'D', now])
        S = Q.append([(now[0]-1)%10000, 'S', now])
        L = Q.append([(now[0]*10 + now[0]//1000)%10000, 'L', now])
        R = Q.append([(now[0]//10) + 1000*(now[0]%10), 'R', now])