s = input()
if s.startswith('0x'):
    print(eval(s))
elif s.startswith('0'):
    print(int(s, 8))
else:
    print(s)