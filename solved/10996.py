n = int(input())
for y in range(n*2):
    for x in range(n):
        print('*' if (x+y)%2==0 else ' ', end='')
    print()