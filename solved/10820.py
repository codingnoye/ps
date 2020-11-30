for line in open(0):
    a=len(list(filter(lambda c:'a'<=c<='z', line)))
    b=len(list(filter(lambda c:'A'<=c<='Z', line)))
    c=len(list(filter(lambda c:'0'<=c<='9', line)))
    d=len(list(filter(lambda c:c==' ', line)))
    print(a, b, c, d)