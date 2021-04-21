a,b,c=map(int,input().split(':'))
d,e,f=map(int,input().split(':'))
g=a*3600+b*60+c
h=d*3600+e*60+f
i=((h-g+24*3600)%(24*3600))
print(f'{i//3600:02}:{i%3600//60:02}:{i%60:02}')