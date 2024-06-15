import heapq
import sys

n=int(sys.stdin.readline())
m=int(sys.stdin.readline())
inf=int(1e9)
adj_mat=[[] for _ in range(n+1)]
for _ in range(m):
    start,end,w=map(int,sys.stdin.readline().split())
    adj_mat[start].append((end,w))
start,end=map(int,sys.stdin.readline().split())

# dijkstra algorithm start!!!!!!!
def dijstra(start):
    global inf,n,m,adj_mat
    edge_list=[]#(dist,node)
    cost_list=[inf for _ in range(n+1)]
    cost_list[start]=0
    
    #start node
    for end,w in adj_mat[start]:
        cost_list[end]=min(w,cost_list[end])
        heapq.heappush(edge_list,(w,end))
    
    #after
    while edge_list:
        dist,start=heapq.heappop(edge_list)
        if(cost_list[start]>=dist):
            for end,w in adj_mat[start]:
                if(cost_list[end]>dist+w):
                    cost_list[end]=dist+w
                    heapq.heappush(edge_list,(dist+w,end))
    return cost_list
print(dijstra(start)[end])