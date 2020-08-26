T = int(input())

def find1(C, CNTs, CNTw, Ws, Ww, NextC):
    mx = 0
    for s in range(CNTs+1):
        for w in range(CNTw+1):
            now = Ws*s + Ww*w
            if now <= C:
                res = s + w + find2(NextC, CNTs-s, CNTw-w, Ws, Ww)
                if (mx < res): 
                    mx = res
            else: break
    return mx
dp2 = dict()
def find2(C, CNTs, CNTw, Ws, Ww):
    if (CNTs, CNTw) in dp2: return dp2[(CNTs, CNTw)]
    mx = 0
    for s in range(CNTs+1):
        for w in range(CNTw+1):
            now = Ws*s + Ww*w
            if now <= C:
                res = s + w
                if (mx < res): mx = res
            else: break
    dp2[(CNTs, CNTw)] = mx
    return mx
for _ in range(T):
    dp2 = dict()
    Ca, Cb = map(int, input().split())
    CNTs, CNTw = map(int, input().split())
    Ws, Ww = map(int, input().split())
    mx = 0
    print(find1(Ca, CNTs, CNTw, Ws, Ww, Cb))