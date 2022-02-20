a, b = map(int, input().split())
d = (a-b+10)%10
if d == 1 or d == 9:
    print("Yes")
else:
    print("No")