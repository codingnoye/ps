N=int(input())
print(min(N,N-input().count('L')//2+1))