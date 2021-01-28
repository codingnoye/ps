board = [*eval('[*map(int, input().split())],'*9)]

zeros = []
xx = [set(range(1, 10)) for _ in range(9)]
yy = [set(range(1, 10)) for _ in range(9)]
s = [set(range(1, 10)) for _ in range(9)]

for y in range(9):
    for x in range(9):
        if board[y][x] == 0:
            zeros.append((y, x))
        else:
            c = board[y][x]
            if c in xx[x]: xx[x].remove(c)
            if c in yy[y]: yy[y].remove(c)
            if c in s[3*(y//3)+(x//3)]: s[3*(y//3)+(x//3)].remove(c)

def dfs(z):
    global zeros, board
    if z>=len(zeros):
        for line in board:
            print(*line)
        exit(0)
    y, x = zeros[z]
    for c in range(1, 10):
        can = xx[x] & yy[y] & s[3*(y//3)+(x//3)]
        if c not in can: continue
        board[y][x] = c
        xx[x].remove(c)
        yy[y].remove(c)
        s[3*(y//3)+(x//3)].remove(c)
        dfs(z+1)
        board[y][x] = 0
        xx[x].add(c)
        yy[y].add(c)
        s[3*(y//3)+(x//3)].add(c)

dfs(0)