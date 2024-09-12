def makecases(n):
    cases=[]
    tmp=[0]*n
    def bt(idx):
        nonlocal tmp,n
        if(idx==n):
            cases.append(tmp.copy())
        else:
            for i in range(2):
                tmp[idx]=i
                bt(idx+1)
    bt(0)
    return cases

n,k=map(int,input().split())
foods=[*map(int,input().split())]
cases=makecases(n)
candidates=0
for ca in cases:
    cur_s=0
    stacked_s=0
    for flag,i in zip(ca,foods):
        if(flag==0): continue
        cur_s+=i
        if(cur_s>=k):
            stacked_s+=(cur_s-k)
            cur_s=0
    candidates=max(candidates,stacked_s)

print(candidates)