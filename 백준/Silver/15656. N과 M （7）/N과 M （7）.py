n,m=map(int,input().split())
l1=sorted(list(map(int,input().split())))
def makecases():
    cases=[]
    tmp=[0]*m
    def bt(idx):
        if(idx==m):
            real1=[l1[i] for i in tmp]
            cases.append(real1.copy())
        else:
            for i in range(n):
                tmp[idx]=i
                bt(idx+1)
    
    bt(0)
    return cases

for i in makecases():
    print(*i)