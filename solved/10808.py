a=[0]*26
for c in input():a[ord(c)-97]+=1
print(*a)