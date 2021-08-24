S, T = map(int, input().split())

def rc(s=0, t=1, d=0):
    if d==2:
        for i in range(S, -1, -1):
            if i+s <= S and i*t <= T:
                return i+1
        return 0
    else:
        res = 0
        for i in range(S, -1, -1):
            res += rc(i+s, i*t, d+1)
        return res

print(rc())