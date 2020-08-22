now = 0
mx = 0
for i in range(4):
    now += eval('-'+input().replace(' ', '+'))
    mx = mx if mx>now else now
print(mx)