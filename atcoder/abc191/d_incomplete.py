from decimal import Decimal
import math
A, B, R = map(lambda x:int(Decimal(x)*10000), input().split())

def countLine(a, b):
    global A, B, R
    c = a+B-b
    t = (A+c)**2+2*(R**2-A**2-c**2)
    if t<0: return 0
    ist = int(math.sqrt(t))
    if ist**2 == t:
        x1 = (A+c)//2+ist
        x2 = (A+c)//2-ist
        y1 = x1 - a + b
        y2 = x2 - a + b
        res = 0
        if x1%10000 == 0 and y1%10000 == 0: res += 1
        if x2%10000 == 0 and y2%10000 == 0: res += 1
        return res + (x1-x2)//10000
    else:
        x1 = math.floor((A+c)//2+ist)
        x2 = math.ceil((A+c)//2-ist)
        return (x1-x2)//10000

sa, sb = A//10000*10000, B//10000*10000
border = 0
a, b = sa, sb
while True:
    border += countLine(a, b)
    a -= 10000
    b += 10000
    if ((A-a)**2 + (B-b)**2 > R**2): break

a, b = sa+10000, sb-10000
while True:
    border += countLine(a, b)
    a += 10000
    b -= 10000
    if ((A-a)**2 + (B-b)**2 > R**2): break

print(border)