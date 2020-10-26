N = int(input())
i = 0
n = 666
while True:
    tmp = n
    while tmp>=666:
        if tmp%1000 == 666:
            i+=1
            if N==i:
                print(n)
                exit(0)
            break
        tmp //= 10
    n += 1