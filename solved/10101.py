a = sorted([int(input()), int(input()), int(input())])
if sum(a)!=180: print("Error")
elif a[0]==a[1]:
    if a[1]==a[2]: print("Equilateral")
    else: print("Isosceles")
else:
    if a[1]==a[2]: print("Isosceles")
    else: print("Scalene")