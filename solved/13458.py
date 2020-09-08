input()
A=map(int,input().split())
B,C=map(int,input().split())
print(sum([max(0,a-B+C-1)//C+1 for a in A]))