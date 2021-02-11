for _ in range(int(input())):
    lia = []
    lib = []
    for __ in range(int(input())):
        a, b = input().split()
        lia.append(int(a))
        lib.append(int(a)*float(b))
    print(sum(lia), round(sum(lib)/sum(lia), 1))
