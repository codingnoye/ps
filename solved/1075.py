N = input()[:-2]
F = int(input())
i = 0
while True:
    if int(N+f'{i:02}')%F == 0:
        print(f'{i:02}')
        exit(0)
    i += 1