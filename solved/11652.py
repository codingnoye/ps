from collections import Counter as C
c=C([*open(0)][1:])
print(max(c,key=lambda k:(c[k],-int(k))))