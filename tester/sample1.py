from tester import tester
import random
t = tester(['../answer'], ['pypy3', '../_2.py'])

#random.seed(0)
for i in range(10000):
    N = random.randint(1, 6)
    S = random.randint(-10, 10)
    tc = f"{N} {S}\n"
    for i in range(N):
        tc += str(random.randint(-10, 10))+" "
    tc += '\n'
    equal, right, wrong = t.test(tc)
    if not equal:
        print('Case:')
        print(tc)
        print('Answer:')
        print(right)
        print('Output:')
        print(wrong)
