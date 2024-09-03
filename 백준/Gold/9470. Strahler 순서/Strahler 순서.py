import sys
from collections import deque
t=int(sys.stdin.readline())
for _ in range(t):
    k,m,p=map(int,sys.stdin.readline().split())
    graph=[[] for _ in range(m+1)]
    indegree=[0]*(m+1)
    in_n=[[0]*(m+1) for _ in range(m+1)]
    result=[1]*(m+1)
    
    for _ in range(p):
        x,y=map(int,sys.stdin.readline().split())
        graph[x].append(y)
        indegree[y]+=1

    q=deque()
    for i in range(1,m+1):
        if indegree[i]==0:
            q.append(i)
    
    while q:
        node=q.popleft()
        for i in graph[node]:
            indegree[i]-=1
            in_n[i][result[node]]+=1
            if indegree[i]==0:
                q.append(i)
            tmp=result[node]+1 if in_n[i][result[node]]>1 else result[node]
            result[i]=max(tmp,result[i])

    print(k,max(result))