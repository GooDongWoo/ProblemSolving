import sys
h,w=map(int,sys.stdin.readline().split())
walls=[*map(int,sys.stdin.readline().split())]
start=0
res=0
def sol(start):
    global h,w,walls,res
    init=start
    idx=start+1
    while idx<=len(walls)-1:
        if(walls[idx]>=walls[start]):#지금까지의 합을 계산하고 이를 더하고 새로운 start만들고 idx=start+1
            th=min(walls[start],walls[idx])
            for i in range(start,idx+1):
                res+=max(th-walls[i],0)
            start=idx
            idx+=1
        else:
            idx+=1
    if(init==start):
        walls[start]=max(walls[init+1:len(walls)])
    return start
while start<len(walls)-1:
    start=sol(start)
print(res)