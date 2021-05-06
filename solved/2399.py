input();a=sorted([*map(int,input().split())])
print(2*sum((2*d-len(a)+1)*a[d]for d in range(len(a))))