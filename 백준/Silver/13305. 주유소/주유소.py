import sys
n=int(sys.stdin.readline())
roads=[*map(int,sys.stdin.readline().split())]
cost=[*map(int,sys.stdin.readline().split())]
res=0
mincost=cost[0]
res+=roads[0]*mincost
for idx in range(1,len(cost)-1):
    mincost=min(mincost,cost[idx])
    res+=roads[idx]*mincost
print(res)