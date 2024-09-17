n,m=map(int,input().split())
l1=sorted(list(map(int,input().split())))
def makecases():
    global n,m,l1
    cases=set()
    tmp=[0]*m
    def bt(idx,bef):
        if(idx==m):
            real1=tuple([l1[i] for i in tmp])
            cases.add(real1)
        else:
            for i in range(bef+1,n):
                tmp[idx]=i
                bt(idx+1,i)
    bt(0,-1)
    return sorted(list(cases))

for i in makecases():
    print(*i)