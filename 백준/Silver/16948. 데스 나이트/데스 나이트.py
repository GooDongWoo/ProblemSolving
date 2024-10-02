from collections import deque
import sys
n=int(input())
r1,c1,r2,c2=map(int,input().split())

def bfs(sy,sx,ey,ex,n):
    v=[[0]*n for _ in range(n)]
    dy_dx=[(-2, -1), (-2, 1), (0, -2), (0, 2), (2, -1), (2, 1)]
    
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
                if(0<=ny<n and 0<=nx<n and v[ny][nx]==0):
                    if((ny,nx)==(ey,ex)):
                        print(t)
                        return
                    q.append((ny,nx))
                    v[ny][nx]=1
    print(-1)
    return

bfs(r1,c1,r2,c2,n)