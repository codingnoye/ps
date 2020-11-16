def f(n):
 a=1
 while n:
  a*=n
  n-=1
 return a
n,k=map(int,input().split())
print(f(n+k-1)//f(n)//f(k-1)%1000000000)