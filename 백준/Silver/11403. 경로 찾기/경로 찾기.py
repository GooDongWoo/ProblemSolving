import sys
from collections import deque
n=int(sys.stdin.readline())
adj_mat=[0 for _ in range(n)]
for i in range(n):
    adj_mat[i]=list(map(int,sys.stdin.readline().split()))

def bfs(start):
    global n,adj_mat,visited
    
    q=deque()
    q.append(start)
    parent=q.pop()
    for child,ox in enumerate(adj_mat[parent]):
        if(ox==1 and visited[child]==0):
            q.append(child)

    while q:
        parent=q.pop()
        if(visited[parent]==0):
            visited[parent]=1
            for child,ox in enumerate(adj_mat[parent]):
                if(ox==1 and visited[child]==0):
                    q.append(child)
    adj_mat[start]=visited.copy()

for i in range(n):
    visited=[0]*n
    bfs(i)
    sys.stdout.write(" ".join(list(map(str,adj_mat[i]))))
    sys.stdout.write(f'\n')