for _ in range(int(input())):
    N = int(input())
    rooms = [False] * (N+1)
    for step in range(1, N+1):
        for i in range(0, N+1, step):
            rooms[i] = not rooms[i]
    print(len([*filter(lambda x:x, rooms[1:])]))