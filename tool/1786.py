from tester import tester
import random
t = tester(['../answer'], ['../_.bin'])

random.seed(0)
pool = ['A', 'B']
for i in range(10000):
    tc = ""
    tc += ''.join(random.choice(pool) for i in range(random.randint(2,6))) + '\n'
    tc += ''.join(random.choice(pool) for i in range(random.randint(1,3))) + '\n'
    equal, right, wrong = t.test(tc)
    if not equal:
        print('Case:')
        print(tc)
        print('Answer:')
        print(right)
        print('Output:')
        print(wrong)
