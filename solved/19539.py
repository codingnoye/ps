input()
x=sum(i//2-i%2 for i in map(int,input().split()))
print('NO'if 0>x or x%3 else'YES')