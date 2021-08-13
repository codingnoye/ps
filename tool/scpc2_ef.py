from error_find import tester
import random
t = tester(['./scpc2'])

TC = 10
L = 100
def line():
    return '1'*L
for i in range(10000):
    tc = f'{TC}\n'
    for i in range(TC):
        tc += f'{L} {random.randint(1, L-1)}\n'
        tc += line()+'\n'
    try:
        out, err = t.test(tc)
        if err:
            print('Case:')
            print(tc)
            print('Answer:')
            print(''.join(out))
            print('Error:')
            print(err)
    except:
        print("ERROR!!")
        print(tc)