import sys
from collections import deque
input=sys.stdin.readline

n,q=map(int,input().split())
mat=[list(map(int,input().split())) for _ in range(2**n)]
querys=list(map(int,input().split()))

def rotate(y,x,w):
    global n,mat
    tmp=[i[x:x+w] for i in mat[y:y+w]]
    tmp=[*zip(*tmp)]
    tmp=[i[::-1] for i in tmp]
    for i in range(w):
        for j in range(w):
            mat[y+i][x+j]=tmp[i][j]
    return

def tornado(l):
    global n
    last=2**(n)
    step=2**l
    for i in range(0,last,step):
        for j in range(0,last,step):
            rotate(i,j,2**l)
    return

def fire():
    global n,mat
    t_mat=[[0]*(2**n) for _ in range(2**n)]
    dy_dx=[(1,0),(0,1),(-1,0),(0,-1)]
    N=2**n
    for i in range(N):
        for j in range(N):
            cnt=0
            for dy,dx in dy_dx:
                ny,nx=i+dy,j+dx
                if(0<=ny<N and 0<=nx<N and mat[ny][nx]):cnt+=1
            if(cnt<3):t_mat[i][j]=max(0,mat[i][j]-1)
            else:t_mat[i][j]=mat[i][j]
    mat=t_mat
    return

def firestorm(l):
    tornado(l)
    fire()
    return

def dfs(sy,sx):
    global n,mat,v
    if(v[sy][sx]==1 or mat[sy][sx]==0):
        v[sy][sx]=1
        return 0
    dy_dx=[(1,0),(0,1),(-1,0),(0,-1)]
    stck=deque()
    stck.append((sy,sx))
    cnt=0
    while stck:
        y,x=stck.pop()
        if(v[y][x]!=0):continue
        v[y][x]=1
        cnt+=1
        for dy,dx in dy_dx:
            ny,nx=y+dy,x+dx
            if(0<=ny<2**n and 0<=nx<2**n and v[ny][nx]==0 and mat[ny][nx]):
                stck.append((ny,nx))
    return cnt

for l in querys:
    firestorm(l)

left=0
for i in range(2**n):
    for j in range(2**n):
        left+=mat[i][j]

v=[[0]*(2**n) for _ in range(2**n)]
candis=0
for i in range(2**n):
    for j in range(2**n):
        candis=max(candis,dfs(i,j))

print(left,candis,sep='\n')