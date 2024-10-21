import sys
from collections import deque
input = sys.stdin.readline
n,m,=map(int,input().split())
mat=[[0]*(m+2) for _ in range(n+2)]
for i in range(1,n+1):
    mat[i][1:m+1]=map(int,input().split())
tmp_mat=[[0]*(m+2) for _ in range(n+2)]

cnt=0
def chckcheese():
    global n,m,mat
    for i in range(1,n+1):
        for j in range(1,m+1):
            if mat[i][j]:return True
    return False

def aircheck():
    global n,m,mat
    v=[[0]*(m+2) for _ in range(n+2)]
    dy_dx=[(1,0),(0,1),(-1,0),(0,-1)]
    q=deque([(0,0)])
    v[0][0]=1
    mat[0][0]=2
    while q:
        p=q.popleft()
        for dy,dx in dy_dx:
            y,x=p[0]+dy,p[1]+dx
            if 0<=y<n+2 and 0<=x<m+2 and v[y][x]==0 and mat[y][x]==0:
                mat[y][x]=2
                v[y][x]=1
                q.append((y,x))
    return

def cheeseDecrease():
    global n,m,mat,tmp_mat
    for i in range(1,n+1):
        for j in range(1,m+1):
            if mat[i][j]==1:
                cnt=0
                for dy,dx in [(1,0),(0,1),(-1,0),(0,-1)]:
                    if mat[i+dy][j+dx]==2:
                        cnt+=1
                if cnt>=2:
                    tmp_mat[i][j]=0
                else:
                    tmp_mat[i][j]=1
            else:
                tmp_mat[i][j]=0
    mat=tmp_mat
    tmp_mat=[[0]*(m+2) for _ in range(n+2)]
    return

while chckcheese():
    cnt+=1
    aircheck()
    cheeseDecrease()

print(cnt)