from tester import tester
import random
t = tester(['python3', '../ab.py'], ['../_3_.bin'])

random.seed(1)
for i in range(10000):
    A = random.randint(10**900000, 10**1000000)
    B = random.randint(10**900000, 10**1000000)
    tc = f'{A} {B}'
    equal, right, wrong = t.test(tc)
    if not equal:
        print('Case:')
        print(tc)
        print('Answer:')
        print(right)
        print('Output:')
        print(wrong)
