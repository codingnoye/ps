from tester import tester
from tqdm import tqdm
import random
t = tester(['../_.bin'], ['../1017'])

random.seed(0)
pool = list(range(1, 101))
for i in tqdm(range(1000)):
    N = random.randint(1, 10)
    tc = [N] + random.sample(pool, N)
    equal, right, wrong = t.test(tc, isStr=False)
    if not equal:
        print('Case:')
        print(tc)
        print('Answer:')
        print(right)
        print('Output:')
        print(wrong)
