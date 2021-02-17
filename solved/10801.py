A = map(int, input().split())
B = map(int, input().split())
w = 0
for AB in zip(A, B):
    if AB[0]>AB[1]: w+=1
    elif AB[0]<AB[1]: w-=1
print('B' if w<0 else 'A' if w>0 else 'D')