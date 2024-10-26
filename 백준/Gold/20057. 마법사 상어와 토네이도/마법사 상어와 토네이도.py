import sys
input = sys.stdin.readline

n=int(input())
mat=[list(map(int,input().split())) for _ in range(n)]
bef=0
for i in range(n):
    for j in range(n):
        bef+=mat[i][j]

dirdict=dict()
dirdict[(0,-1)]=0
dirdict[(1,0)]=1
dirdict[(0,1)]=2
dirdict[(-1,0)]=3

sandleft=[0]*4  #left,down,right,up
sandleft[0]=[[0,0,0.02,0,0],[0,0.1,0.07,0.01,0],[0.05,0,0,0,0],[0,0.1,0.07,0.01,0],[0,0,0.02,0,0]]
sandleft[2]=[i[::-1] for i in sandleft[0]]
sandleft[1]=[*zip(*sandleft[2])]
sandleft[3]=[*zip(*sandleft[0])]

def makeRotateList():
    global n
    res=[]
    direct=[(0,1),(1,0),(0,-1),(-1,0)]
    didx=0
    v=[[0]*n for _ in range(n)]
    cy,cx=(0,0)
    while ((cy,cx)!=(n//2,n//2)):
        res.append((cy,cx))
        v[cy][cx]=1
        ny,nx=cy+direct[didx][0],cx+direct[didx][1]
        if not (0<=ny<n and 0<=nx<n and v[ny][nx]==0):
            didx=(didx+1)%4
            ny,nx=cy+direct[didx][0],cx+direct[didx][1]
        cy,cx=ny,nx
    return res

def tornado(dir,ny,nx):
    global n,mat,sandleft
    sandleft[dir]
    left=mat[ny][nx]
    for i in range(5):
        for j in range(5):
            left-=int(mat[ny][nx]*sandleft[dir][i][j])
            if(0<=ny-2+i<n and 0<=nx-2+j<n):
                mat[ny-2+i][nx-2+j]+=int(mat[ny][nx]*sandleft[dir][i][j])
    mat[ny][nx]=0
    if dir==0:
        if(0<=nx-1<n):mat[ny][nx-1]+=left
    elif dir==1:
        if(0<=ny+1<n):mat[ny+1][nx]+=left
    elif dir==2:
        if(0<=nx+1<n):mat[ny][nx+1]+=left
    else:
        if(0<=ny-1<n):mat[ny-1][nx]+=left
    return

movelist=makeRotateList()[::-1]

cy,cx=(n//2,n//2)
for i in range(len(movelist)):
    ny,nx=movelist[i]
    diff=(ny-cy,nx-cx)
    tornado(dirdict[diff],ny,nx)
    cy,cx=ny,nx

aft=0
for i in range(n):
    for j in range(n):
        aft+=mat[i][j]
print(bef-aft)