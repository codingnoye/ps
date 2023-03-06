import subprocess as sp
import os

class tester:
    right = None
    left = None
    def __init__(self, right, wrong):
        self.right = right
        self.wrong = wrong
    
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
        pWrong = sp.Popen(
            self.wrong,
            env = os.environ.copy(),
            stdin = sp.PIPE,
            stdout = sp.PIPE,
            text=True
        )
        pRight.stdin.write(tcInput)
        pRight.stdin.flush()
        pWrong.stdin.write(tcInput)
        pWrong.stdin.flush()
        outRraw, errR = pRight.communicate()
        outR = list(' '.join(outRraw).split())
        outWraw, errW = pWrong.communicate()
        outW = list(' '.join(outWraw).split())
        return outR == outW, outRraw, outWraw