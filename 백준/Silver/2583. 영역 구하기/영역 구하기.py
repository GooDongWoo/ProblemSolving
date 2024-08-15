import sys
from collections import deque
m,n,k = map(int, sys.stdin.readline().split())
mat=[[0]*m for _ in range(n)]
for _ in range(k):
    x1,y1,x2,y2 = map(int, sys.stdin.readline().split())
    for i in range(x1,x2):
        for j in range(y1,y2):
            mat[i][j]=1
emptyspace=[]
for i in range(n):
    for j in range(m):
        if mat[i][j]==0:
            emptyspace.append((i,j))


def bfs(sy,sx):
    global n,m,k,mat,emptyspace,v
    q=deque([(sy,sx)])
    v[sy][sx]=1
    eacharea_cnt=0
    while q:
        y,x=q.popleft()
        eacharea_cnt+=1
        for dy,dx in [(0,1),(1,0),(0,-1),(-1,0)]:
            ny,nx=y+dy,x+dx
            if 0<=ny<n and 0<=nx<m and v[ny][nx]==0 and mat[ny][nx]==0:
                q.append((ny,nx))
                v[ny][nx]=1
    return eacharea_cnt


v=[[0]*m for _ in range(n)]
areacnt=0
areas=[]
for i in range(n):
    for j in range(m):
        if v[i][j]==0 and mat[i][j]==0:
            areas.append(bfs(i,j))
            areacnt+=1
print(areacnt)
print(*sorted(areas))