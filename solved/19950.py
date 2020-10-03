a,b,c,d,e,f = map(int, input().split())
input()
g = [*map(int,input().split())] + [round(((d-a)**2+(e-b)**2+(f-c)**2)**.5, 2)]
if max(g) <= sum(g)-max(g): print("YES")
else: print("NO")