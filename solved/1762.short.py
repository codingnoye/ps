A,c=[set()for i in[0]*7**6],0
for l in[*open(0)][1:]:u,v=map(int,l.split());c+=len(A[u]&A[v]);A[u]|={v};A[v]|={u}
print(c)