i=input().split()
for n in range(1,9**9):
 if sum(1 for j in i if n%int(j)<1)>2:
  print(n)
  break