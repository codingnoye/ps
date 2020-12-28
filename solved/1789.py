S = int(input())
sm = 0
i = 1
cnt = 0
while sm<=S:
    sm += i
    i += 1
    cnt += 1
print(cnt-1)