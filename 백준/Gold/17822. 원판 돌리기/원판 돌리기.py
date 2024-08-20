import sys
from collections import deque
n,m,t=map(int,sys.stdin.readline().split())
pans=[0]*(n)
zerocnt=[0]*(n) #sum한다음 뺄때 전체 n*m에서 빼야할 것들 미리 개수로 카운팅
dy_dx=[(1,0),(0,1),(-1,0),(0,-1)]
for i in range(n):
    pans[i]=list(map(int,sys.stdin.readline().split()))

def bfs(sy,sx):
    global n,m,t,pans,zerocnt,v,dy_dx,motioncnt
    q=deque()
    q.append((sy,sx))
    v[sy][sx]=1
    target=pans[sy][sx]
    sames=[(sy,sx)]
    while q:
        p=q.popleft()
        for dy,dx in dy_dx:
            ny,nx=p[0]+dy,(p[1]+dx)%m
            if(0<=ny<n and pans[ny][nx]==target and v[ny][nx]==0):
                motioncnt+=1
                q.append((ny,nx))
                v[ny][nx]=1
                sames.append((ny,nx))
    
    if(len(sames)!=1):
        for y,x in sames:
            pans[y][x]=0
            zerocnt[y]+=1
            
for _ in range(t):
    x,d,k=map(int,sys.stdin.readline().split())
    k=k if d==0 else m-k
    mul=1
    while x*mul<=n:
        tmp=deque(pans[x*mul-1])
        tmp.rotate(k)
        pans[x*mul-1]=list(tmp)
        mul+=1

    #모든 pans에서 인접한 것을 찾고 인접하면 전부 0으로 바꿔버리기;;# bfs가즈아
    v=[[0]*m for _ in range(n)]
    motioncnt=0
    for i in range(n):
        for j in range(m):
            if(v[i][j]==0 and pans[i][j]!=0):
                bfs(i,j)
                
    if(motioncnt==0):
        total_sum=sum([sum(i) for i in pans])
        total_len=n*m-sum(zerocnt)
        if(total_len!=0):
            avg=total_sum/total_len
            for i in range(n):
                for j in range(m):
                    if(pans[i][j]!=0):
                        if(pans[i][j]>avg):
                            pans[i][j]-=1
                        elif(pans[i][j]<avg):
                            pans[i][j]+=1

print(sum([sum(i) for i in pans]))