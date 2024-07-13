import sys
h,w=map(int,sys.stdin.readline().split())
walls=[*map(int,sys.stdin.readline().split())]
start=0
end=len(walls)-1
res=0
def sol(start):
    global h,w,walls,res,end
    init=start
    idx=start+1
    while idx<=end:
        if(walls[idx]>=walls[start]):#지금까지의 합을 계산하고 이를 더하고 새로운 start만들고 idx=start+1
            th=min(walls[start],walls[idx])
            for i in range(start,idx+1):
                res+=max(th-walls[i],0)
            start=idx
            idx+=1
        else:
            idx+=1
    if(init==start):
        walls[start]=max(walls[init+1:end+1])
    return start
while start<end:
    start=sol(start)
print(res)