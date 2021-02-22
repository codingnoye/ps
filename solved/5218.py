for _ in range(int(input())):
    A, B = input().split()
    print('Distances: ', end='')
    for i in range(len(A)):
        y, x = ord(A[i]), ord(B[i])
        print(x-y if x>=y else x+26-y , end=' ')
    print('')