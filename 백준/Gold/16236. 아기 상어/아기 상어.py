import sys
from collections import deque
n=int(sys.stdin.readline())
mat=[0 for _ in range(n)]
sr=0;sc=0
for i in range(n):
    mat[i]=list(map(int,sys.stdin.readline().split()))
    for j in range(n):
        if(mat[i][j]==9):
            sr=i;sc=j
            mat[i][j]=0
dy_dx=[(-1,0),(0,-1),(1,0),(0,1)]
ate=0
lv=2

def bfs(row,col):
    global n,mat,dy_dx,ate,lv,sr,sc,time
    res=[]
    v=[[0]*n for _ in range(n)]
    q=deque()
    q.append((row,col))
    v[row][col]=1
    cnter=0
    while q:
        cnter+=1
        for _ in range(len(q)):
            p=q.popleft()
            for dy,dx in dy_dx:
                ny,nx=p[0]+dy,p[1]+dx
                if(0<=ny<n and 0<=nx<n and v[ny][nx]==0 and mat[ny][nx]<=lv):
                    if(0<mat[ny][nx]<lv):
                        res.append((ny,nx))
                    v[ny][nx]=1
                    q.append((ny,nx))
        if(res):
            res.sort(key=lambda x:(x[0],x[1]))
            ny,nx=res[0]
            mat[ny][nx]=0
            ate+=1
            if(ate==lv):
                ate=0
                lv+=1
            sr,sc=ny,nx
            time+=cnter
            return True
    return False

time=0
while 1:
    if (bfs(sr,sc)):pass
    else:
        print(time)
        break