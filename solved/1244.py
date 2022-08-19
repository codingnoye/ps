N = int(input())
switches = [-1] + [*map(int, input().split())]

Q = int(input())

for q in range(Q):
    s, i = map(int, input().split())
    if s == 1:
        for j in range(i, N+1, i):
            switches[j] = 1 - switches[j]
        # print(*switches[1:])
    else:
        mxl = 0
        for l in range(min(i, N-i+1)):
            lst = switches[i-l:i+l+1]
            # print(lst, lst[::-1])
            if lst != lst[::-1]: break
            mxl = l
        for j in range(i-mxl, i+mxl+1):
            switches[j] = 1 - switches[j]
        # print(*switches[1:])

switches = switches[1:]
for i in range(N//20 + 1):
    print(*switches[i*20:(i+1)*20])