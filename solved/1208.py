import sys
sys.setrecursionlimit(10**6)
N, S = map(int, input().split())
arr = list(sorted(map(int, input().split())))
arrP = arr[:len(arr)//2]
Pz = arrP.count(0)
arrN = arr[len(arr)//2:]
Pn = arrN.count(0)
def sumComb(a, idx=0):
    if idx == len(a):
        return {0: 1}
    if idx == len(a)-1:
        if a[idx] == 0: return {0: 2}
        return {0: 1, a[idx]: 1}
    sub = sumComb(a, idx+1)
    now = a[idx]
    own = {}
    for k in sub:
        if k==0:
            own[k] = sub[k]
        elif k in own:
            own[k] += sub[k]
        else:
            own[k] = sub[k]
        newk = k+now
        if newk in own:
            own[newk] = own[newk] + sub[k]
        else:
            own[newk] = sub[k]
    return own

comP = sumComb(arrP)
comN = sumComb(arrN)
#print(arrP, comP)
#print(arrN, comN)
res = 0
for kP in comP:
    kN = S - kP
    if kN in comN:
        res += comP[kP] * comN[kN]

if S==0: res-=1
print(res)