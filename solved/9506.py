while True:
    i = int(input())
    if i==-1: break
    divs = []
    for j in range(1, i):
        if i%j==0:
            divs.append(j)
    if sum(divs) == i:
        print(f'{i} = '+' + '.join(map(str, divs)))
    else:
        print(f'{i} is NOT perfect.')