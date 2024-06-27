import sys
from collections import deque
def bfs(start):#start:(row,col)
    global n,m,map_mat,visited,dy_dx_list
    if(visited[start[0]][start[1]]):
        return
    q=deque()
    q.append(start)
    visited[start[0]][start[1]]=1
    while q:
        parent=q.popleft()
        for dy,dx in dy_dx_list:
            if(0<=parent[0]+dy<n and 0<=parent[1]+dx<m and visited[parent[0]+dy][parent[1]+dx]==0 and map_mat[parent[0]+dy][parent[1]+dx]!=1):
                visited[parent[0]+dy][parent[1]+dx]=1
                q.append((parent[0]+dy,parent[1]+dx))
    
n,m=map(int,sys.stdin.readline().split())
map_mat=[[0 for _ in range(m)] for _ in range(n)]
z_list=[]
o_list=[]
t_list=[]
dy_dx_list=[[1,0],[0,1],[-1,0],[0,-1]]
for i in range(n):
    tmp=list(map(int,sys.stdin.readline().split()))
    for j in range(m):
        map_mat[i][j]=tmp[j]
        if(tmp[j]==0):
            z_list.append((i,j))
        elif (tmp[j]==1):
            o_list.append((i,j))
        else:
            t_list.append((i,j))

#먼저 3 벽을 고르고 그곳에 1을 칠한다. 그리고 매번 그 벽을 0으로 초기화후 다시 칠한다.
#그리고 모든 바이러스(t_list)에 대해 bfs를 돌리고 0의 개수를 구해보고 최댓값보다 크면 갱산
result=0
for i in range(len(z_list)-2):# 첫번째 벽
    for j in range(i+1,len(z_list)-1):# 두번째 벽
        for k in range(j+1,len(z_list)):# 세번째 벽
            visited=[[0 for _ in range(m)] for _ in range(n)]
            visited[z_list[i][0]][z_list[i][1]]=visited[z_list[j][0]][z_list[j][1]]=visited[z_list[k][0]][z_list[k][1]]=1
            for v in t_list:
                bfs(v)
            cnt=0
            #빈칸 개수 구하는 것은 visited의 0의 개수에서 기존 벽의개수(len(o_list))을 뺸다. 이중 포문으로 끝
            for t1 in range(n):
                for t2 in range(m):
                    if not(visited[t1][t2]):
                        cnt+=1
            cnt-=len(o_list)
            result=max(result,cnt)
print(result)
