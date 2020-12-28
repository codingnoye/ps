li = []
for _ in range(int(input())):
 a, b, c = map(int, input().split())
 if a==b and b==c: li += [10000+1000*a]
 elif a==b: li += [1000+100*a]
 elif b==c: li += [1000+100*b]
 elif c==a: li += [1000+100*c]
 else: li += [max(a,b,c)*100]
print(max(li))