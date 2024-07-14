import sys
from collections import deque
n,l,r=map(int,sys.stdin.readline().split())
mat=[list(map(int,sys.stdin.readline().split())) for _ in range(n)]
dy_dx=[(1,0),(0,1),(-1,0),(0,-1)]


def dfs(row,col):#dfs하고 그 시작에서 갈 수 있는 곳은 가고 v처리하고 res에 추가함. 전부 다 돌고 stck비면 나와서 res에 있는 것들의 합/나라수 한 것을 다시 mat에 적용 lazy해야함..
    global n,l,r,mat,v,tmat,change,dy_dx
    if(v[row][col]):
        return
    
    stck=deque()
    res=[]
    stck.append((row,col))
    while stck:
        p=stck.pop()
        if v[p[0]][p[1]]==0:
            res.append(p)
            v[p[0]][p[1]]=1
            for dy,dx in dy_dx:
                ny,nx=p[0]+dy,p[1]+dx
                if(0<=ny<n and 0<=nx<n and v[ny][nx]==0 and l<=abs(mat[ny][nx]-mat[p[0]][p[1]])<=r):
                    stck.append((ny,nx))
    change+=len(res)-1
    res_avg=0
    for i in res:
        res_avg+=mat[i[0]][i[1]]
    res_avg=int(res_avg/len(res))
    for i in res:
        tmat[i[0]][i[1]]=res_avg

days=0
while 1:
    v=[[0]*n for _ in range(n)]
    tmat=[[0]*n for _ in range(n)]
    change=0
    for i in range(n):
        for j in range(n):
            dfs(i,j)
    mat=tmat
    if(change==0):
        print(days)
        break
    days+=1