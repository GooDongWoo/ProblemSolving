import sys
from collections import deque
t=int(sys.stdin.readline())
for _ in range(t):
    n,p=map(int,sys.stdin.readline().split())
    times=list(map(int,sys.stdin.readline().split()))
    result=[0]*(n+1)
    graph=[[] for _ in range(n+1)]
    indegree=[0]*(n+1)
    for _ in range(p):
        x,y=map(int,sys.stdin.readline().split())
        graph[x].append(y)
        indegree[y]+=1

    target_node=int(sys.stdin.readline())
    
    q=deque()
    for i in range(1,n+1):
        if indegree[i]==0:
            q.append(i)
            result[i]=times[i-1]
    
    while q:
        node=q.popleft()
        for i in graph[node]:
            indegree[i]-=1
            result[i]=max(result[i],result[node]+times[i-1])
            if indegree[i]==0:
                q.append(i)

    print(result[target_node])