import re
T = int(input())
for _ in range(T):
    print('YES' if re.fullmatch("(100+1+|01)+", input()) else 'NO')