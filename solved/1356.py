a=input()
for i in range(1,len(a)):
 if eval('*'.join(a[:i])+'=='+'*'.join(a[i:])):print('YES');exit(0)
print('NO')