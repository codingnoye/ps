D=R=L=0
for c in input():C=c>'(';R+=C*L or C*D-C;D+=1-C-C;L=C
print(R)