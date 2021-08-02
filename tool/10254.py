from tester import tester
import random
t = tester(['../10254.right'], ['../10254.bin'])

random.seed(1)
for i in range(100000):
    T = random.randint(1, 1)
    tc = f'{T}\n'
    for _ in range(T):
        N = random.randint(10, 10)
        tc += f'{N}\n'
        for _ in range(N):
            tc += f'{random.randint(-10000000, 10000000)} {random.randint(-10000000, 10000000)}\n'
    _equal, right, wrong = t.test(tc)
    a, b, c, d = map(int, right.split())
    rv= (a-c)**2 + (b-d)**2
    a, b, c, d = map(int, wrong.split())
    wv = (a-c)**2 + (b-d)**2
    equal = rv == wv
    if not equal:
        print('Case:')
        print(tc)
        print('Answer:')
        print(right)
        print(rv)
        print('Output:')
        print(wrong)
        print(wv)
