import sys
from collections import deque
sys.setrecursionlimit(10 ** 8)
n,m=map(int,sys.stdin.readline().split())
map_mat=[list(map(int,sys.stdin.readline().split())) for _ in range(n)]
dy_dx_l=[(1,0),(0,1),(-1,0),(0,-1)]
visited=[[-1 for _ in range(m)] for _ in range(n)] # not visited:-1, visited:0, visted but ans_p: x>=1
path=deque()

def dfs(cur=(0,0)):
    global n,m,map_mat,dy_dx_l,visited,path
    path.append(cur)
    if(cur[0]==n-1 and cur[1]==m-1):# last ans goal
        for dir in path:
            if(dir==cur):
                break
            visited[dir[0]][dir[1]]+=1
        return

    if(visited[cur[0]][cur[1]]==-1):#not visited
        visited[cur[0]][cur[1]]=0
        for dy,dx in dy_dx_l:
            if(0<=cur[0]+dy<n and 0<=cur[1]+dx<m and map_mat[cur[0]][cur[1]]>map_mat[cur[0]+dy][cur[1]+dx] and visited[cur[0]+dy][cur[1]+dx]!=0):
                dfs((cur[0]+dy,cur[1]+dx))
                path.pop()
        return

    elif(visited[cur[0]][cur[1]]>=1):#visited but ans path
        for dir in path:
            if(dir==cur):
                break
            visited[dir[0]][dir[1]]+=visited[cur[0]][cur[1]]
        return
dfs()
print(visited[0][0])