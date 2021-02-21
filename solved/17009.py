i=lambda:int(input())
a=i()*3+i()*2+i()-i()*3-i()*2-i()
print('B'if a<0 else'A'if a>0 else'T')