a,b,c=map(int,sorted(input().split()))
if a==b==c:print(10000+a*1000)
elif a==b or b==c:print(1000+b*100)
else:print(c*100)