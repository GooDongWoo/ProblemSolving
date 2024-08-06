from collections import deque
n,m=map(int,input().split())
mat=[list(map(int,input().split())) for _ in range(n)]
neigh=[[[] for _ in range(m)] for _ in range(n)]
for i in range(n):
    for j in range(m):
        for di,dj in [(-1,0),(1,0),(0,-1),(0,1)]:
            ni,nj=i+di,j+dj
            if(0<=ni<n and 0<=nj<m):neigh[i][j].append((ni,nj))

def bfs(sy=0,sx=0):
    global mat,n,m,neigh
    v=[[0]*m for _ in range(n)]
    q=deque()
    q.append((sy,sx))
    v[sy][sx]=1
    while q:
        y,x=q.popleft()
        for ny,nx in neigh[y][x]:
            if(mat[ny][nx]==0 and v[ny][nx]==0):
                v[ny][nx]=1
                q.append((ny,nx))
    for i in range(n):
        for j in range(m):
            if(v[i][j]>0):mat[i][j]=2

def melting():
    global n,m,mat,neigh,remain
    tmp_mat=[v.copy() for v in mat]
    for i in range(n):
        for j in range(m):
            if mat[i][j]==1 and any([mat[y][x]==2 for y,x in neigh[i][j]]):
                tmp_mat[i][j]=2
    mat=tmp_mat
    chckAirConnect()
    cnt=0
    for i in range(n):
        for j in range(m):
            if(mat[i][j]==1):
                cnt+=1
    remain.append(cnt)
    if(cnt):return 1
    else: return 0
    
def chckAirConnect():
    global n,m,mat,holes,neigh
    first=[]
    for y,x in holes:
        for ny,nx in neigh[y][x]:
            if(mat[ny][nx]==2):
                first.append((y,x))
    if(first):
        v=[[0]*m for _ in range(n)]
        q=deque()
        for sy,sx in first:
            q.append((sy,sx))
            v[sy][sx]=1
        while q:
            y,x=q.popleft()
            for ny,nx in neigh[y][x]:
                if(mat[ny][nx]==0 and v[ny][nx]==0):
                    v[ny][nx]=1
                    q.append((ny,nx))
        for i in range(n):
            for j in range(m):
                if(v[i][j]>0):mat[i][j]=2
cnt=0
for i in range(n):
    for j in range(m):
        if(mat[i][j]==1):cnt+=1
remain=[cnt]
bfs()
holes=set()
for i in range(n):
    for j in range(m):
        if(mat[i][j]==0):holes.add((i,j))
time=0
while melting():pass
print(len(remain)-1)
print(remain[-2])