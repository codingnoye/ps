import subprocess as sp
import os

class tester:
    right = None
    def __init__(self, right):
        self.right = right
    
    def test(self, tcInput, isStr=True):
        if not isStr:
            tcInput = ' '.join(map(str, tcInput))

        pRight = sp.Popen(
            self.right,
            env = os.environ.copy(),
            stdin = sp.PIPE,
            stdout = sp.PIPE,
            text=True
        )
        pRight.stdin.write(tcInput)
        pRight.stdin.flush()
        outRraw, errR = pRight.communicate()
        outR = list(' '.join(outRraw).split())
        return outR, errR