N = input()
t1 = 10
t2 = 1
lasti = 0
res = 0
for i in range(1, len(N)):
    res += i*(t1-t2)
    t1*=10
    t2*=10
    lasti = i
print(res + len(N)*(int(N)-t2+1))