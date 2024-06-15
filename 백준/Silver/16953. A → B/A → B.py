import sys
sys.setrecursionlimit(100000)

start,end=map(int,input().split())
res=99999999
def bt(target,cnt):
    global end,res
    if(target==end):
        res=min(res,cnt)
    #1
    if(target*2<=end):
        bt(target*2,cnt+1)
    #2
    if((target*10)+1<=end):
        bt((target*10)+1,cnt+1)

bt(start,1)
if(res==99999999):
    print(-1)
else:
    print(res)