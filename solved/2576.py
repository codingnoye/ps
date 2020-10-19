a=[*filter(lambda x:x%2,(int(input())for i in range(7)))]
if len(a)==0:print(-1)
else:
    print(sum(a))
    print(min(a))