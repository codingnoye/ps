n, k = map(int, input().split())
nodes = [1] + [i for i in range(2, n+1)] + [1]

before = 0
now = 0
poped = 0
i = 0
answer = [0] * n
ai = 0
while poped < n:
    next = nodes[now]
    if i==k:
        answer[ai]=now
        ai+=1
        i=0
        poped+=1
        nodes[before] = next
    else:
        before = now
    i+=1
    now = next
print('<'+', '.join(map(str, answer))+'>')