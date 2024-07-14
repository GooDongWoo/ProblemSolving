import sys
from collections import deque
n,m=map(int,sys.stdin.readline().split())
mat=[[0 for _ in range(m)] for _ in range(n)]
ice=set()
cnt=0
for i in range(n):
    mat[i]=list(map(int,sys.stdin.readline().split()))
    for j in range(m):
        if(mat[i][j]):
            ice.add((i,j))
            cnt+=1
dy_dx=[(1,0),(0,1),(-1,0),(0,-1)]

def dfs(set1):
    global dy_dx,n,m,mat,ice,cnt
    if(set1):
        start=list(set1)[0]
    else:
        return 0
    visited=[[0 for _ in range(m)] for _ in range(n)]
    stck=deque()
    stck.append(start)
    incnt=0
    while stck:
        p=stck.pop()
        if(visited[p[0]][p[1]]==0):
            visited[p[0]][p[1]]=1
            incnt+=1
            for dy,dx in dy_dx:
                ny,nx=p[0]+dy,p[1]+dx
                if(0<=ny<n and 0<=nx<m and visited[ny][nx]==0 and mat[ny][nx]>0):
                    stck.append((ny,nx))
    return incnt

def aftYear():
    global dy_dx,n,m,mat,ice,cnt
    tmat=[[0 for _ in range(m)] for _ in range(n)]
    r_list=[]
    for i in ice:
        sea=0
        for dy,dx in dy_dx:
            ny,nx=i[0]+dy,i[1]+dx
            if(not mat[ny][nx]):
                sea+=1
        tmat[i[0]][i[1]]=max(mat[i[0]][i[1]]-sea,0)
        if(tmat[i[0]][i[1]]==0):
            cnt-=1
            r_list.append(i)
    for i in r_list:
        ice.discard(i)
    return tmat

y_cnt=0
aftice=cnt
while (cnt and aftice==cnt):
    mat=aftYear()
    aftice=dfs(ice)
    y_cnt+=1
if(cnt==0):
    print(0)
else:
    print(y_cnt)