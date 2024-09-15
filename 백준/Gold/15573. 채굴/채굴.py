import heapq
from collections import deque
n,m,k=map(int,input().split())
mat=[list(map(int,input().split())) for _ in range(n)]
dy_dx=[(1,0),(0,1),(-1,0),(0,-1)]
v=[[0]*m for _ in range(n)]

candidates=[]
for i in range(1,n):
    candidates.append((mat[i][0],i,0))
    v[i][0]=1

for i in range(1,n):
    candidates.append((mat[i][m-1],i,m-1))
    v[i][m-1]=1

for i in range(m):
    candidates.append((mat[0][i],0,i))
    v[0][i]=1

heapq.heapify(candidates)
q=deque()
cnter=0

while candidates and cnter<k:
    target=candidates[0][0]
    while candidates and candidates[0][0]==target:
        _,r,c=heapq.heappop(candidates)
        q.append((r,c))
        cnter+=1
    while q:
        y,x=q.popleft()
        for dy,dx in dy_dx:
            ny,nx=y+dy,x+dx
            if(0<=ny<n and 0<=nx<m and v[ny][nx]==0):
                if(mat[ny][nx]<=target):
                    q.append((ny,nx))
                    v[ny][nx]=1
                    cnter+=1
                else:
                    heapq.heappush(candidates,(mat[ny][nx],ny,nx))
                    v[ny][nx]=1

print(target)