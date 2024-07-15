import sys
from collections import deque
r,c,t=map(int,sys.stdin.readline().split())
mat=[list(map(int,sys.stdin.readline().split())) for _ in range(r)]
ac=0
for i in range(r):
    if(mat[i][0]==-1):
        ac=i
        break
dy_dx=[(1,0),(0,1),(-1,0),(0,-1)]
neigh=[[[] for _ in range(c)] for _ in range(r)]
for i in range(r):
    for j in range(c):
        for dy,dx in dy_dx:
            ny,nx=i+dy,j+dx
            if(0<=ny<r and 0<=nx<c):
                neigh[i][j].append((ny,nx))
#함수는 2개 만들어야 한다.
# 1. 각 r,c를 돌며 mat에서의 값을 가며 그 값이 5보다 크면 tmat에다가 4방향에 나눠준다. 그리고 모든 r,c를 돌면 그것을 mat,tmat=tmat,mat(필요없는 거니 재활용 어차피 tmat은 그 값에서 더하지 않고 모두 새로 할당하니)
# 2. ac위치에서 위는 반시계, 아래는 시계방향으로 2d배열을 회전시킨다. ac에 도달하면 먼지는 전부 제거
def diffusion():
    global r,c,t,mat,ac,neigh
    tmat=[[0]*c for _ in range(r)]
    for i in range(r):
        for j in range(c):
            if(mat[i][j]>4):
                tmat[i][j]+=mat[i][j]
                for ny,nx in neigh[i][j]:
                    if(mat[ny][nx]!=-1):
                        tmat[i][j]-=mat[i][j]//5
                        tmat[ny][nx]+=mat[i][j]//5
            else:
                tmat[i][j]+=mat[i][j]
    return tmat

def rotation():
    global r,c,t,mat,ac,neigh
    #위 반시계
    for i in range(ac-1,0,-1):#맨 왼쪽열| 내려감
        mat[i][0]=mat[i-1][0]
    for i in range(0,c-1):#맨위쪽 행<-
        mat[0][i]=mat[0][i+1]
    for i in range(0,ac):#맨 오른쪽열| 올라감
        mat[i][c-1]=mat[i+1][c-1]
    for i in range(c-1,0,-1):#맨아래 ac행->
        mat[ac][i]=mat[ac][i-1]
    mat[ac][1]=0
    
    #아래 시계
    bc=ac+1
    for i in range((bc+1),r-1):#맨 왼쪽열| 올라감
        mat[i][0]=mat[i+1][0]
    for i in range(0,c-1):#맨아래 행<-
        mat[r-1][i]=mat[r-1][i+1]
    for i in range(r-1,bc,-1):#맨 오른쪽열| 내려감
        mat[i][c-1]=mat[i-1][c-1]
    for i in range(c-1,0,-1):#맨위쪽 ac행->
        mat[bc][i]=mat[bc][i-1]
    mat[bc][1]=0
for i in range(t):
    mat=diffusion()
    rotation()
res=0
for i in range(r):
    res+=sum(mat[i])
print(res+2)