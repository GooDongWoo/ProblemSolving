import sys
import heapq
input=sys.stdin.readline

INF=int(1e9)
n,m=map(int,input().split())

adj_v = [[] for _ in range(n)]
for _ in range(m):
    a, b, c = map(int, input().split())
    a -= 1; b -= 1
    adj_v[a].append((c, b))
    adj_v[b].append((c, a))

h=[]
v=[0]*n
start=0
h.append((0,start)) # (dist,sp)
res=[]
while h:
    dist, sp = heapq.heappop(h)
    if v[sp] == 1 : continue
    
    v[sp] = 1
    res.append(dist)
    
    for i in range(len(adj_v[sp])):
        w, end = adj_v[sp][i]
        if v[end] == 0:
            heapq.heappush(h,(w,end))

print(sum(res)-max(res))