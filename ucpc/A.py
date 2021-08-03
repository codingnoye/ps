s = input()

for i in range(1, 4):
    start = int(s[:i])
    now = start
    j = 0
    full = False
    while str(now) == s[j:j+len(str(now))]:
        if j+len(str(now)) == len(s):
            print(start, now)
            exit(0)
        j += len(str(now))
        now += 1