import sys
from collections import deque
n,p=map(int,sys.stdin.readline().split())
graph=[[] for _ in range(n+1)]
indegree=[0]*(n+1)
result=[]
for _ in range(p):
    x,y=map(int,sys.stdin.readline().split())
    graph[x].append(y)
    indegree[y]+=1

q=deque()
for i in range(1,n+1):
    if indegree[i]==0:
        q.append(i)
        result.append(i)

while q:
    node=q.popleft()
    for i in graph[node]:
        indegree[i]-=1
        if indegree[i]==0:
            q.append(i)
            result.append(i)

print(*result)