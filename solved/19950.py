a,b,c,d,e,f=map(int,input().split())
input()
g=[*map(int,input().split())]+[((d-a)**2+(e-b)**2+(f-c)**2)**.5]
print("YES"if max(g)*2<=sum(g)else"NO")