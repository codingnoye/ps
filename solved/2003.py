N, M = map(int, input().split())
arr = list(map(int, input().split()))
l = r = 0
acc = 0
cnt = 0
while l<N or r<N:
    if r < N:
        if acc<M:
            acc += arr[r]
            r += 1
        elif acc>M:
            acc -= arr[l]
            l += 1
        else:
            cnt += 1
            acc -= arr[l]
            l += 1
    else:
        if acc>M:
            acc -= arr[l]
            l += 1
        elif acc==M:
            cnt += 1
            acc -= arr[l]
            l += 1
        else:
            break
print(cnt)