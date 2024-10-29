import sys
import heapq
input=sys.stdin.readline
n=int(input())
m=int(input())
INF=int(1e9)
adj_v=[[INF]*n for _ in range(n)]
for _ in range(m):
    s,e,w=map(int,input().split())
    s-=1;e-=1
    adj_v[s][e]=min(adj_v[s][e],w)

def dijkstra(start,end):
    global n,INF,adj_v
    dp=[INF]*n
    dp[start]=0
    v=[0]*n
    h=[]
    route=[[] for _ in range(n)]
    heapq.heappush(h,(0,start,-1))
    while h:
        cost,cur,bef=heapq.heappop(h)
        if v[cur]:continue
        v[cur]=1
        route[cur]=route[bef].copy()+[cur]
        for i in range(n):
            if(dp[i]>cost+adj_v[cur][i]):
                dp[i]=cost+adj_v[cur][i]
                heapq.heappush(h,(dp[i],i,cur))
    return dp,route
st,et=map(lambda x:int(x)-1,input().split())
dp,route=dijkstra(st,et)
print(dp[et])
print(len(route[et]))
print(*[*map(lambda x:x+1,route[et])])