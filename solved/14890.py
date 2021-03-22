def check(line, L):
    last = -1
    uplock = L
    downlock = 0
    for i in line:
        if last == -1:
            last = i
            uplock -= 1
            downlock -= 1
        elif last == i:
            uplock -= 1
            downlock -= 1
        elif last+1 == i:
            if uplock<=0:
                last = i
                uplock = L-1
            else:
                #print("1!", last, i)
                return False
        elif last-1 == i:
            if downlock<=0:
                last = i
                downlock = L-1
                uplock = L+L-1
            else:
                #print("2!", last, i)
                return False
        else:
            #print("3!", last, i)
            return False
    #print("4!", last, i)
    return downlock<=0

# while True:
#     l = [*map(int, input().split())]
#     print(check(l, int(input())))

N, L = map(int, input().split())
arr = [[*map(int, input().split())] for _ in range(N)]
arrT = [[arr[x][y]for x in range(N)] for y in range(N)]
cnt = 0
for i in range(N):
    # print(arr[i])
    # print(check(arr[i], L))
    cnt += 0+check(arr[i], L)
    # print(arrT[i])
    # print(check(arrT[i], L))
    cnt += 0+check(arrT[i], L)
print(cnt)