li = list(range(1, int(input())+1))
while len(li)>1:
    print(li[0], end=' ')
    li = li[1:]
    li = li[1:]+[li[0]]
print(li[0])