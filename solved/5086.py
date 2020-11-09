while True:
    a,b=map(int,input().split()) 
    if not(a or b): exit(0)
    if a%b==0: print('multiple')
    elif b%a==0: print('factor')
    else: print('neither')