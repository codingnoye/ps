N = int(input())

trace = []
while N != 0:
    if N % 2 != 0:
        trace.append('A')
        N -= 1
    else:
        trace.append('B')
        N //= 2
print(''.join(trace[::-1]))