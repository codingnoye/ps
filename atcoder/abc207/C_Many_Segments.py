N = int(input())
tuples = [list(map(int, input().split())) for _ in range(N)]

L = 1
R = 2
def inter(la, lb):
    bordera = [None, la[0]<=2, la[0]%2==1]
    borderb = [None, lb[0]<=2, lb[0]%2==1]
    # l = [t, L, R]
    if la[L] == lb[R] and bordera[L] and borderb[R]:
        return True
    elif la[L] < lb[R] and lb[L] <= la[L]:
        return True
    elif la[R] == lb[L] and bordera[R] and borderb[L]:
        return True
    elif lb[L] < la[R] and la[L] <= lb[L]:
        return True
    return False

res = 0
for i in range(len(tuples)):
    for j in range(i+1, len(tuples)):
        if inter(tuples[i], tuples[j]):
            res += 1

print(res)