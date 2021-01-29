i=[*open(0)]
for l in i[1:-1]:print(f"{l[:-1]} is{' NOT'if int(l)%int(i[0])else''} a multiple of {i[0][:-1]}.")