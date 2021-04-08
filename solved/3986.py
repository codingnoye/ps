res = 0
for i in range(int(input())):
    st = ['x']
    for c in input():
        if st[-1] == c:
            st.pop()
        else:
            st.append(c)
    if len(st)==1: res += 1
print(res)