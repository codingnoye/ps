N, B = input().split()
B = int(B)
sm = 0
for i in range(len(N)):
    n = int(N[-i-1]) if '0'<=N[-i-1]<='9' else 10+ord(N[-i-1])-ord('A')
    sm += B**i * n
print(sm)