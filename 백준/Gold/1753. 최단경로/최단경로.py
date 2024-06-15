import sys
import heapq

V,E=map(int,input().split())
start_node=int(input())
graph = [[] for _ in range(V+1)]
E_list=[]
cost_list=[int(1e9) for _ in range(V+1)]
cost_list[start_node]=0

for _ in range(E):
    start,end,w=map(int,sys.stdin.readline().split())
    graph[start].append((end,w))


heapq.heappush(E_list,(0,start_node))
while(E_list):
    dist, now=heapq.heappop(E_list)
    if cost_list[now] >= dist:
        #현재 노드와 연결된 인접 노드 확인
        for i in graph[now]:
            cost =dist+ i[1]
            if cost < cost_list[i[0]] :
                cost_list[i[0]] = cost
                heapq.heappush(E_list,(cost,i[0]))


for i in range(1,len(cost_list)):
    if(cost_list[i]<int(1e9)):
        sys.stdout.write(f'{cost_list[i]}\n')
    else:
        sys.stdout.write(f'INF\n')