n,m=map(int,input().split())
l1=sorted(list(set([*map(int,input().split())])))
nm=len(l1)
def makecases():
    global n,m,l1,nm
    cases=[]
    tmp=[0]*m
    def bt(idx):
        if(idx==m):
            ttmp=[l1[i] for i in tmp]
            cases.append(ttmp)
        else:
            for i in range(nm):
                tmp[idx]=i
                bt(idx+1)
    bt(0)
    return cases
for i in makecases():
    print(*i)