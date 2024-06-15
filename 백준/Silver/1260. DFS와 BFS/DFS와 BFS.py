from collections import deque
import sys
input=sys.stdin.readline
print=sys.stdout.write

n_node, n_edge, num_start =map(int, input().split()) #처음 노드개수, 엣지개수, 시작 노드번호
adj_v=[[] for _ in range(n_node+1)]

for _ in range(n_edge): # 간선들 adj vector에 추가
    n1,n2 =map(int, input().split())
    adj_v[n1].append(n2)
    adj_v[n2].append(n1)
    
for i in range(n_node):
    adj_v[i]=list(set(adj_v[i]))
    adj_v[i].sort()

def dfs(graph, v, visited):
    visited[v] = True # 방문 처리
    print(f'{v} ') # 현재 노드 출력
    for i in sorted(graph[v]): # 오름차순으로 이웃한 노드
        if not visited[i]: # 아직 방문하지 않은 노드가 있다면 방문
            dfs(graph, i, visited)

visited = [False] * (n_node+1)
# dfs 함수 실행
dfs(adj_v, num_start, visited)


def BFS(start):
    global adj_v
    visited=[0]*(n_node+1)
    que1=deque([start])

    while(que1): # que1이 비워질때까지..
        tmp=que1.popleft()
        if(visited[tmp]==1):
            continue
        print(f'{tmp} ')
        visited[tmp]=1
        for item in adj_v[tmp]:
            if(visited[item]==0): #visited가 0인 것만
                que1.append(item)
            
            

print(f'\n')
BFS(num_start)