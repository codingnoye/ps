N = int(input())
nums = [*map(int, input().split())]

last = -1
maxlen = 0
nowlen = 0
for num in nums+[0]:
    if num >= last:
        nowlen += 1
        last = num
    else:
        maxlen = max(maxlen, nowlen)
        nowlen = 1
        last = num

last = -1
maxlen2 = 0
nowlen = 0
for num in nums+[100002]:
    if num <= last:
        nowlen += 1
        last = num
    else:
        maxlen2 = max(maxlen2, nowlen)
        nowlen = 1
        last = num
print(max(maxlen, maxlen2))