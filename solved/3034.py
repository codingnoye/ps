n,w,h=map(int,input().split())
exec("print('DNAE'[int(input())**2>w*w+h*h::2]);"*n)