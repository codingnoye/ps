from collections import Counter as c
print(''.join(i[0] for i in sorted(filter(lambda x:x[1]>4,c(map(lambda x:x[0],open(0))).items())))or'PREDAJA')