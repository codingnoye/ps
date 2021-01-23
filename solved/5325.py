for _ in range(int(input())):
    a = int(input())
    for i in range(int(input())):
        a += eval('*'.join(input().split()))
    print(a)