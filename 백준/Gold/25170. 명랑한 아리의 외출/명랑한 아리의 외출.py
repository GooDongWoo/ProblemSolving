import sys
from collections import deque
input=sys.stdin.readline
n,m,t=map(int,input().split())
tasks=[list(map(int,input().split())) for _ in range(n)]
times=[list(map(int,input().split())) for _ in range(n)]

v=[[[-1]*(t+1) for _ in range(m)] for _ in range(n)]

q=deque()
q.append((0,0,0,0))#y,x,ctask,ctime
while q:
    y,x,ctask,ctime=q.popleft()
    if(ctask<v[y][x][ctime]):continue
    for dy,dx in [(1,0),(0,1),(1,1)]:
        ny,nx=y+dy,x+dx
        if(0<=ny<n and 0<=nx<m):
            if(ctime+1<=t and ctask>v[ny][nx][ctime+1]):
                q.append((ny,nx,ctask,ctime+1))
                v[ny][nx][ctime+1]=ctask
            if(ctime+1+times[ny][nx]<=t and ctask+tasks[ny][nx]>v[ny][nx][ctime+1+times[ny][nx]]):
                q.append((ny,nx,ctask+tasks[ny][nx],ctime+1+times[ny][nx]))
                v[ny][nx][ctime+1+times[ny][nx]]=ctask+tasks[ny][nx]
print(max(v[-1][-1]))