T = int(input())
for t in range(T):
    N = int(input())
    d3 = N//3
    if N%3 == 0:
        print(d3, d3)
    elif N%3 == 1:
        print(d3+1, d3)
    else:
        print(d3, d3+1)