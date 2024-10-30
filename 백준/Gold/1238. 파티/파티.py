import sys
import heapq
input=sys.stdin.readline
INF=int(1e9)
n,m,x=map(int,input().split())
x-=1
adj_m=[[INF]*n for _ in range(n)]
for _ in range(m):
    start,end,w=map(int,input().split())
    start-=1;end-=1
    adj_m[start][end]=min(adj_m[start][end],w)

def dijkstra1(start):
    global n,m,adj_m,INF
    dp=[INF]*n
    v=[0]*n
    q=[]
    heapq.heappush(q,(0,start))
    while q:
        cost,cur=heapq.heappop(q)
        if(v[cur]):continue
        v[cur]=1
        for nxt in range(n):
            ncost=adj_m[cur][nxt]
            if(dp[nxt]>ncost+cost):
                dp[nxt]=ncost+cost
                heapq.heappush(q,(ncost+cost,nxt))
    return dp

def dijkstra2(start):
    global n,m,adj_m,INF
    dp=[INF]*n
    v=[0]*n
    q=[]
    heapq.heappush(q,(0,start))
    while q:
        cost,cur=heapq.heappop(q)
        if(v[cur]):continue
        v[cur]=1
        for nxt in range(n):
            ncost=adj_m[nxt][cur]
            if(dp[nxt]>ncost+cost):
                dp[nxt]=ncost+cost
                heapq.heappush(q,(ncost+cost,nxt))
    return dp

dp1=dijkstra1(x)
dp2=dijkstra2(x)
res=0
for i in range(n):
    if(i==x):continue
    res=max(res,dp1[i]+dp2[i])
print(res)