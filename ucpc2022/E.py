from datetime import datetime

N = int(input())

if N==0:
    print(0)
    exit(0)
arr = [0] * N
for i in range(N):
    strdate, strtime, score = input().split()
    score = int(score)
    std = strdate + ' ' + strtime
    d = datetime.strptime(std, "%Y/%m/%d %H:%M:%S")
    arr[i] = (d, score)
    
arr.sort(key=lambda x: x[0])

tN = arr[-1][0]

total_div = sum(max(0.5**(int((tN-ti).total_seconds())/31536000), 0.9**(N-1-i)) for i, (ti, si) in enumerate(arr))

total_score = sum(max(0.5**(int((tN-ti).total_seconds())/31536000), 0.9**(N-1-i))*si for i, (ti, si) in enumerate(arr))
# print(total_score/total_div)
print(round(total_score/total_div))