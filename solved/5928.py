D,H,M=map(int,input().split())
print(max(-1,D*1440+H*60+M-16511))