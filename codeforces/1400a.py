T = int(input())
for _ in range(T):
    N = int(input())
    s = input()
    res = ''
    for i in range(0, len(s), 2):
        res += s[i]
    print(res)