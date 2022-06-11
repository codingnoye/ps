n=int(input())
print(2*sum(x*(i+i-n+1)for i,x in enumerate(sorted(map(int,input().split())))))