dq = [0]*100001

for _ in range(int(input())):
    F = input()
    N = int(input())
    l, r = 0, N-1
    LTR = True
    if N==0:
        input()
        r = -1
    else:
        for i, elem in enumerate(map(int, input()[1:-1].split(','))):
            dq[i] = elem
    
    for c in F:
        if c=='R':
            LTR = not LTR
        else:
            if l>r:
                print('error')
                break
            elif LTR: l+=1
            else: r-=1
    else: print('['+','.join(map(str, dq[l:r+1] if LTR else dq[l:r+1][::-1]))+']')