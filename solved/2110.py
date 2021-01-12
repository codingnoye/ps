import sys
input = lambda: sys.stdin.readline().strip()
N, C = map(int, input().split())
arr = sorted((int(input()) for i in range(N)))
def calc(d):
    global arr
    last = -99999999999
    cnt = 0
    for a in arr:
        if a - last >= d:
            cnt += 1
            last = a
    return cnt
l, r = 1, arr[-1] - arr[0]
ans = 0
while l<=r:
    m = (l+r)//2
    res = calc(m)
    #print(l, m, r, res)
    if res<C:
        r = m-1
    else:
        ans = max(ans, m)
        l = m+1
print(ans)