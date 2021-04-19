input()
i=[*map(int,input().split())]
a=dict(zip(sorted({*i}),range(9**9)))
print(*(a[x]for x in i))