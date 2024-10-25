import sys
import heapq
input = sys.stdin.readline

n,e=map(int,input().split())
INF=int(1e8)
adj_v=[[INF]*n for _ in range(n)]

for _ in range(e):
    start,end,w=map(int,input().split())
    start-=1
    end-=1
    adj_v[start][end]=w
    adj_v[end][start]=w

for i in range(n):
    adj_v[i][i]=0

t1,t2=map(lambda x:int(x)-1,input().split())

def dijkstra(start):
    global n, INF, adj_v
    w = [INF] * n
    v = [0] * n
    h = []
    w[start] = 0
    heapq.heappush(h, (0, start))
    
    while h:
        cost,node=heapq.heappop(h)
        if(v[node]):continue
        v[node]=1
        for i in range(n):
            if(adj_v[node][i]!= INF and adj_v[node][i]!=0):
                if(v[i]==0 and cost+adj_v[node][i]<w[i]):
                    w[i]=cost+adj_v[node][i]
                    heapq.heappush(h,(cost+adj_v[node][i],i))
    return w

startlist=dijkstra(0)
t1_length=startlist[t1]
t2_length=startlist[t2]

t1list=dijkstra(t1)
t2list=dijkstra(t2)

t1t2length=t1list[t2]
tot=min(t1_length+t1t2length+t2list[n-1],t2_length+t1t2length+t1list[n-1])
tot= tot if tot<INF else -1
print(tot)