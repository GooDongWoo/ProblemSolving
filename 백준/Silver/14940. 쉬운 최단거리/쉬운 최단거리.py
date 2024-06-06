from collections import deque
import sys

n,m=map(int,sys.stdin.readline().split())

row_col_status_mat=[0 for _ in range(n)]
visited=[[0 for _ in range(m)] for _ in range(n)]

for i in range(n):
    row_col_status_mat[i]=list(map(int,sys.stdin.readline().split()))
    if(2 in row_col_status_mat[i]):
        start_y,start_x=i,row_col_status_mat[i].index(2)

cost_row_col_mat=[[0 for _ in range(m)] for _ in range(n)]
for i in range(n):
    for j in range(m):
        if(row_col_status_mat[i][j]==1):
            cost_row_col_mat[i][j]=-1
        elif(row_col_status_mat[i][j]==0):
            cost_row_col_mat[i][j]=0
        else:
            cost_row_col_mat[i][j]=-1
    
def bfs(start_row,start_col):
    global n,m,row_col_status_mat,visited,cost_row_col_mat
    
    dx_list=[0,1,0,-1]
    dy_list=[1,0,-1,0]
    cnt=0
    
    q=deque()
    q.append((start_row,start_col,cnt))
    
    while q:
        parent=q.popleft()
        if(visited[parent[0]][parent[1]]==0 and (row_col_status_mat[parent[0]][parent[1]]!=0)):
            visited[parent[0]][parent[1]]=1
            cost_row_col_mat[parent[0]][parent[1]]=parent[2]
            
            for dy,dx in zip(dy_list,dx_list):
                if(0<=parent[0]+dy<=(n-1) and 0<=parent[1]+dx<=(m-1) and visited[parent[0]+dy][parent[1]+dx]==0 and (row_col_status_mat[parent[0]+dy][parent[1]+dx]!=0)):
                    q.append((parent[0]+dy,parent[1]+dx,parent[2]+1))
    
bfs(start_y,start_x)

for i in range(n):
    sys.stdout.write(f'{" ".join(list(map(str,cost_row_col_mat[i])))}\n')