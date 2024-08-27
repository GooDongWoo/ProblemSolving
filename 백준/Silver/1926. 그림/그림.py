import sys
from collections import deque
n,m=map(int,sys.stdin.readline().split())
mat=[list(map(int,sys.stdin.readline().split())) for _ in range(n)]
dxs=[-1,1,0,0]
dys=[0,0,-1,1]
v=[[0]*m for _ in range(n)]
candidates=[0]
def bfs(sy,sx):
    global v,n,m,mat,dys,dxs
    q=deque()
    q.append((sy,sx))
    v[sy][sx]=1
    cnt=0
    while q:
        p=q.popleft()
        cnt+=1
        for  dy,dx in zip(dys,dxs):
            ny,nx=p[0]+dy, p[1]+dx
            if (0<=ny<n and 0<=nx<m) and (mat[ny][nx]==1 and v[ny][nx]==0):
                v[ny][nx]=1
                q.append((ny,nx))
    return cnt
for i in range(n):
    for j in range(m):
        if mat[i][j]==1 and v[i][j]==0:
            candidates.append(bfs(i,j))
print(len(candidates)-1)
print(max(candidates))