for line in open(0):
    N = int(line)
    now = '1'
    while True:
        if int(now) % N == 0:
            print(len(now))
            break
        now += '1'