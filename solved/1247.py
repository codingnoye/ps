import sys
for _ in[0]*3:
 exec('_+=int(sys.stdin.readline());'*int(input()))
 print('+'if _>0 else'-'if _<0 else'0')