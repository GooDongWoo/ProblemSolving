n,s=map(int,input().split())
a=list(map(int,input().split()))
include=[0]*n
cnt=0
visited=set()
def dfs(th):
    global n,s,a,include,cnt
    tmp=0
    if(th!=-1):
        for idx,val in enumerate(include):
            if(val==1):
                tmp+=a[idx]
        if(tmp==s and sum(include)>0 and not (tuple(include) in visited)):
            cnt+=1
            visited.add(tuple(include))
        if(th==n-1):
            return
    include[th+1]=1
    dfs(th+1)
    include[th+1]=0
    dfs(th+1)
dfs(-1)
print(cnt)