from tester import tester
from tqdm import tqdm
import random
t = tester(['python3', '../D1.py'], ['../D1_yj'])

random.seed(0)
for i in tqdm(range(10000)):
    A = random.randint(3, 7)
    B = random.randint(3, 7)
    while B%2!=0 and A%2!=0:
        B = random.randint(3, 20)
    C = random.randint(1, (A*B)//2)
    T = 1
    tc = f'{T}\n'
    for i in range(T):
        tc += f'{A} {B} {C}\n'
    equal, right, wrong = t.test(tc)
    if not equal:
        print('Case:')
        print(tc)
        print('Answer:')
        print(right)
        print('Output:')
        print(wrong)
