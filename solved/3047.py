a=dict(zip('ABC',sorted(map(int,input().split()))))
print(*map(lambda x:a[x],input()))