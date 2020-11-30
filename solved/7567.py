last = 0
sm = 0
for c in input():
    sm+=10 if c!=last else 5
    last = c
print(sm)