import sys
from collections import deque
input=sys.stdin.readline
n,m=map(int,input().split())
mat1=[list(input().rstrip()) for _ in range(n)]
mat2=[list(input().rstrip()) for _ in range(n)]
newmat=[[0]*m for _ in range(n)]
def dfs(sy,sx):
    global n,m,mat1,mat2
    if(mat1[sy][sx]==mat2[sy][sx]):
        newmat[sy][sx]=mat2[sy][sx]
        return
    stck=deque()
    v=[[0]*m for _ in range(n)]
    bef=mat1[sy][sx]
    aft=mat2[sy][sx]
    stck.append((sy,sx))
    while stck:
        y,x=stck.pop()
        if(v[y][x]):continue
        v[y][x]=1
        newmat[y][x]=aft
        for dy,dx in [(1,0),(0,1),(-1,0),(0,-1)]:
            ny,nx=y+dy,x+dx
            if(0<=ny<n and 0<=nx<m and v[ny][nx]==0 and mat1[ny][nx]==bef):
                stck.append((ny,nx))
    return

for i in range(n):
    for j in range(m):
        dfs(i,j)

for i in range(n):
    for j in range(m):
        if(newmat[i][j]!=mat2[i][j]):
            print("NO")
            exit()
print("YES")