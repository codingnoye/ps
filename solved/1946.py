import sys
input = lambda:sys.stdin.readline()
for T in range(int(input())):
    N = int(input())
    li = sorted([tuple(map(int, input().split())) for i in range(N)])
    last = li[0]
    res = 1
    for i in range(1, len(li)):
        if last[1] > li[i][1]:
            last = li[i]
            res += 1
    print(res)