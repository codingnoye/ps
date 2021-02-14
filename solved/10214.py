for _ in range(int(input())):
    a, b = 0, 0
    for __ in range(9):
        c, d = map(int, input().split())
        a, b = a+c, b+d
    if a==b: print('Draw')
    elif a<b: print('Korea')
    else: print('Yonsei')