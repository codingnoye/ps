n = int(input())
for i in range(n):
    if n==i+sum(map(int, str(i))):
        print(i)
        exit(0)
print(0)