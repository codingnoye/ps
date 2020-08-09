SM, DF = map(int, input().split())
for i in range(SM//2+1):
    if SM-i-i == DF:
        print(SM-i, i)
        break
else: print(-1)