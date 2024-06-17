import sys
import heapq
v,e=map(int,sys.stdin.readline().split())
edge_list=[[] for _ in range(v+1)]
visited=[0]*(v+1)
edge_heap_list=[]
target_edge_list=[]
for _ in range(e):
    start,end,w=map(int,sys.stdin.readline().split())
    edge_list[start].append((w,end))
    edge_list[end].append((w,start))

#1로 이니셜라이즈
edge_heap_list=edge_list[1].copy()
heapq.heapify(edge_heap_list)
# heapq.heappop(edge_heap_list)# edge_heap_list[0]==[], so delete this one
visited[1]=1

while len(edge_heap_list):
    parent=heapq.heappop(edge_heap_list)
    if(visited[parent[1]]==0):
        target_edge_list.append(parent)
        visited[parent[1]]=1
        for child in edge_list[parent[1]]:
            if(visited[child[1]]==0):
                heapq.heappush(edge_heap_list,child)
res=0
for i in range(len(target_edge_list)):
    res+=target_edge_list[i][0]
sys.stdout.write(f'{res}')