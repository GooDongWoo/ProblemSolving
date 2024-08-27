from collections import deque
n=int(input())
t1,t2=map(int,input().split())
m=int(input())
adj=[[] for _ in range(n+1)]
for _ in range(m):
    a,b=map(int,input().split())
    adj[a].append(b)
    adj[b].append(a)

def bfs():
    global n,t1,t2,adj
    q=deque()
    q.append(t1)
    visited=[0]*(n+1)
    visited[t1]=1
    while q:
        cur=q.popleft()
        if cur==t2:
            return visited[t2]-1
        for i in adj[cur]:
            if not visited[i]:
                visited[i]=visited[cur]+1
                q.append(i)
    return -1

print(bfs())