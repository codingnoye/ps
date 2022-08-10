e={(*l.split(),i+1)for i,l in enumerate([*open(0)][1:])}
u={i for i in e if i[0]<i[1]}
u=min(u,e-u,key=len)
print(len(u),*[i[2]for i in u])