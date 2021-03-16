s = input()
countJ = 0
countI = 0
for i in range(len(s)-2):
    if s[i:i+3] == 'JOI':
        countJ += 1
    if s[i:i+3] == 'IOI':
        countI += 1
print(countJ)
print(countI)