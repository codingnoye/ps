def sigma(a):
 return a*(a+1)//2
a, b = map(int, input().split())
print(sigma(max(a,b)) - sigma(min(a,b)-1))