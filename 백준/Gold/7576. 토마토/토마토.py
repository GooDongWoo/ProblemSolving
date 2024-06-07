from collections import deque
import sys
m,n=map(int,sys.stdin.readline().split())
stat_mat=[[0 for _ in range(m)] for _ in range(n)]
riped_list=[]
visited=[[0 for _ in range(m)] for _ in range(n)]

for i in range(n):
    tmp=list(map(int,sys.stdin.readline().split()))
    for j,val in enumerate(tmp):
        stat_mat[i][j]=val
        if(val==1):
            riped_list.append((i,j,0))#row,col,day
        elif(val==-1):
            visited[i][j]=1

def bfs():
    global m,n,stat_mat,riped_list,visited
    dx_list=[0,1,0,-1]
    dy_list=[1,0,-1,0]
    max_date=0
    q=deque()    
    for row,col,day in riped_list:
        q.append((row,col,day))
    
    while q:
        parent=q.popleft()
        if(visited[parent[0]][parent[1]]==0):
            visited[parent[0]][parent[1]]=1
            max_date=max(max_date,parent[2])
            for dy,dx in zip(dy_list,dx_list):
                if(0<=parent[0]+dy<=(n-1) and 0<=parent[1]+dx<=(m-1) and visited[parent[0]+dy][parent[1]+dx]==0):
                    q.append((parent[0]+dy,parent[1]+dx,parent[2]+1))
    return max_date

def chck0(double_list):
    row=len(double_list)
    col=len(double_list[0])
    result=0
    for i in range(row):
        result+=sum(double_list[i])
    if(result==row*col):
        return False
    else:
        return True

ttt=bfs()

if(chck0(visited)):
    print(-1)
else:
    print(ttt)