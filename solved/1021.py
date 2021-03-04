N, M = map(int, input().split())
target = list(map(lambda x:int(x)-1, input().split()))
queue = list(range(N))
now = 0
cnt = 0
while len(target):
    nextItem = target.pop(0)
    next = queue.index(nextItem)
    inner = abs(next - now)
    outter = -abs(now - next) + len(queue)
    cnt += min(inner, outter)
    queue.pop(next)
    if len(queue): now = next%len(queue)
    #print(f'poped {nextItem} at {next}, now is {now}')
print(cnt)