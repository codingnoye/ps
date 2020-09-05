s = input()
if s[:2] == '10': print(10 + int(s[2:]))
else: print(int(s[:1]) + int(s[1:]))