i=[*open(0)]
s=[j[:-1]for j in i[:int(i[0].split()[0])+1]]
print(sum(l[:-1]in s for l in i)-len(s))