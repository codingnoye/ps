import sys
a=[*map(int,sys.stdin.readlines())]
b,c=sorted(a[:4]),sorted(a[4:])
print(sum(b[1:])+sum(c[1:]))