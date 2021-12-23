nums = [('+![]', 3), ('+!![]', 3), ('+!![]+!![]', 1)] + [()]*3997
strs = ['+![]', '+!![]', '+!![]+!![]'] + ['']*3997
# 합만으로 이루어지면 []없이

PLUSED = 1
ISTERM = 2

str9999 = '0'*9999

def filled(x):
    return len(nums[(4000+x)%4000])>0
for ii in range(1):
    for i in [*range(0, 2001)] + [*range(0, -2001, -1)]:
        if filled(i):
            if ii == 0: continue
            minexp = nums[(4000+i)%4000][0]
            minstr = strs[(4000+i)%4000]
            minstrsize = len(minstr)
            minsize = len(minexp)
            minbit = nums[(4000+i)%4000][1]
        else:
            minsize = 9999
            minexp = str9999
            minstr = str9999
            minstrsize = 9999
            minbit = 0
        for a in range(1, i):
            b = i-a
            ma = nums[(4000+a)%4000][1]
            mb = nums[(4000+b)%4000][1]
            ea = nums[(4000+a)%4000][0]
            eb = nums[(4000+b)%4000][0] if mb & PLUSED else f'+{nums[(4000+b)%4000][0]}'
            if a < b:
                tmp = f'{ea}{eb}'
                if len(tmp) < minsize:
                    minsize = len(tmp)
                    minexp = tmp
                    minbit = ma&PLUSED
        for a in range(2, i):
            if i%a == 0:
                b = i//a
                ma = nums[(4000+a)%4000][1]
                mb = nums[(4000+b)%4000][1]
                ea = f'[{nums[(4000+a)%4000][0]}]' if ma & PLUSED or (ma & ISTERM)==0 else f'{nums[(4000+a)%4000][0]}'
                eb = f'[{nums[(4000+b)%4000][0]}]' if mb & PLUSED or (ma & ISTERM)==0 else f'{nums[(4000+b)%4000][0]}'
                if a < b:
                    tmp = f'{ea}*{eb}'
                    if len(tmp) < minsize:
                        minsize = len(tmp)
                        minexp = tmp
                        minbit = 0
        si = str(i)
        for ai in range(1, len(si)):
            try:
                if str(int(si[:ai])) != si[:ai] or str(int(si[ai:])) != si[ai:]: continue
            except:
                continue
            a = int(si[:ai])
            b = int(si[ai:])
            ma = nums[(4000+a)%4000][1]
            mb = nums[(4000+b)%4000][1]
            ea = f'[{nums[(4000+a)%4000][0]}]'
            eb = f'[{nums[(4000+b)%4000][0]}]'
            sa = f'[{strs[(4000+a)%4000]}]'
            sb = f'[{strs[(4000+b)%4000]}]'
            tmp = f'+[{ea}+{eb}]'
            if len(tmp) < minsize:
                minstrsize = len(tmp)
                minstr = tmp
            tmp = f'+[{sa}+{sb}]'
            if len(tmp) < minsize:
                minstrsize = len(tmp)
                minstr = tmp

        if ii != 0:
            for a in range(1, 2001):
                b = a-i
                if not filled(a) or not filled(b): continue
                ma = nums[(4000+a)%4000][1]
                mb = nums[(4000+b)%4000][1]
                ea = nums[(4000+a)%4000][0]
                eb = nums[(4000+b)%4000][0]
                if a < b:
                    tmp = f'{ea}-{eb}'
                    if len(tmp) < minsize:
                        minsize = len(tmp)
                        minexp = tmp
                        minbit = ma&PLUSED
        
        nums[(4000+i)%4000] = (minexp, minbit)
        strs[(4000+i)%4000] = minstr

for i in range(0, 1001):
    e = nums[(4000+i)%4000][0]
    s = strs[(4000+i)%4000]
    b = nums[(4000+i)%4000][1]
    if len(s) < len(e):
        print(s)
    else:
        print(e)