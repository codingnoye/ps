s=''.join(open(0))
q=[(s.count(c),c)for c in'abcdefghijklmnopqrstuvwxyz']
[print(b,end='')for a,b in q if a==max(q)[0]]