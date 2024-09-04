import sys
from collections import deque
n,m=map(int,sys.stdin.readline().split())
mat=[list(map(int,sys.stdin.readline().split())) for _ in range(n)]
dys=[1,1,0,-1,-1,-1,0,1]
dxs=[0,1,1,1,0,-1,-1,-1]
sharks=[]
for i in range(n):
    for j in range(m):
        if(mat[i][j]==1):sharks.append((i,j))

def bfs():
    global n,m,mat,dys,dxs,sharks
    q=deque()
    v=[[0]*m for _ in range(n)]
    
    for shark in sharks:
        q.append(shark)
        v[shark[0]][shark[1]]=1
    
    while q:
        p=q.popleft()
        for dy,dx in zip(dys,dxs):
            ny,nx=p[0]+dy,p[1]+dx
            if(0<=ny<n and 0<=nx<m and not v[ny][nx]):
                v[ny][nx]=v[p[0]][p[1]]+1
                q.append((ny,nx))
                
    return max([max(row) for row in v])

print(bfs()-1)