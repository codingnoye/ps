a,b=max(zip(eval('[*map(int,input().split())]+'*9+'[]'),range(81)))
c,d=divmod(b,9)
print(a,c+1,d+1)