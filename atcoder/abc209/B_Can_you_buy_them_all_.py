N, X = map(int, input().split())
s = sum(map(int, input().split()))
if s-(N//2)<=X:
    print('Yes')
else:
    print('No')