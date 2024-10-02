from collections import deque
import sys
input=sys.stdin.readline
n,m=map(int,input().split())
mat=[list(input().rstrip()) for _ in range(n)]
for i in range(n):
    for j in range(m):
        if(mat[i][j]=='2'):
            sy,sx=i,j

dy_dx=[(1,0),(0,1),(-1,0),(0,-1)]
def bfs():
    global n,m,mat,sy,sx,dy_dx
    v=[[0]*m for _ in range(n)]
    q=deque()
    q.append((sy,sx))
    v[sy][sx]=1
    t=0
    while q:
        cycle=len(q)
        t+=1
        for _ in range(cycle):
            y,x=q.popleft()
            for dy,dx in dy_dx:
                ny,nx=y+dy,x+dx
                if(0<=ny<n and 0<=nx<m and v[ny][nx]==0 and mat[ny][nx]!='1'):
                    if(mat[ny][nx]!='0'):
                        print('TAK')
                        print(t)
                        return
                    else:
                        q.append((ny,nx))
                        v[ny][nx]=1
    print('NIE')

bfs()