N = int(input())
for i in range(N):
    a = input().split()
    v = float(a[0])
    for j in range(1, len(a)):
        if a[j] == '@':
            v *= 3
        elif a[j] == '#':
            v -= 7
        elif a[j] == '%':
            v += 5
    print(f'{v:.2f}')