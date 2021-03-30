i=1
while True:
    a, b, c = map(int, input().split())
    if a==b==c==0: break
    print(f'Case {i}: {a*(c//b)+min(a,c%b)}')
    i += 1