import sys
from collections import deque
n,m=map(int,sys.stdin.readline().split())
map_mat=[0 for _ in range(n)]
o_v=set()
t_v=set()
visited=[[(0,0) for _ in range(m)] for _ in range(n)]# what visited,time
for i in range(n):
    map_mat[i]=list(map(int,sys.stdin.readline().split()))
    for j in range(m):
        if(map_mat[i][j]==1):
            o_v.add((i,j))
        elif(map_mat[i][j]==2):
            t_v.add((i,j))
        elif(map_mat[i][j]==-1):
            visited[i][j]=(-1,0)

def bfs():
    global n,m,map_mat,o_v,t_v,visited
    dy_dx=[[1,0],[0,1],[-1,0],[0,-1]]
    q=deque()
    for o in o_v:
        q.append(o)
        visited[o[0]][o[1]]=(1,1)    
    for t in t_v:
        q.append(t)
        visited[t[0]][t[1]]=(2,1)
    while q:
        p=q.popleft()
        if(visited[p[0]][p[1]][0]==3):
            continue
        for dy,dx in dy_dx:
            if(0<=p[0]+dy<n and 0<=p[1]+dx<m and visited[p[0]+dy][p[1]+dx][0]==0):
                q.append((p[0]+dy,p[1]+dx))
                visited[p[0]+dy][p[1]+dx]=(visited[p[0]][p[1]][0],visited[p[0]][p[1]][1]+1)
            elif(0<=p[0]+dy<n and 0<=p[1]+dx<m and visited[p[0]+dy][p[1]+dx][0]+visited[p[0]][p[1]][0]==3 and visited[p[0]+dy][p[1]+dx][1]==visited[p[0]][p[1]][1]+1):
                visited[p[0]+dy][p[1]+dx]=(3,visited[p[0]][p[1]][1]+1)
    cnter=[0]*3
    for i in range(n):
        for j in range(m):
            if(visited[i][j][0]==1):
                cnter[0]+=1
            elif(visited[i][j][0]==2):
                cnter[1]+=1
            elif(visited[i][j][0]==3):
                cnter[2]+=1
    print(*cnter)
    return
bfs()