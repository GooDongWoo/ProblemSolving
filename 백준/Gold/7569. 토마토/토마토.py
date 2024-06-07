from collections import deque
import sys
m,n,h=map(int,sys.stdin.readline().split())
stat_mat=[[[0 for _ in range(m)] for _ in range(n)] for _ in range(h)]
riped_list=[]
visited=[[[0 for _ in range(m)] for _ in range(n)] for _ in range(h)]

for k in range(h):
    for i in range(n):
        tmp=list(map(int,sys.stdin.readline().split()))
        for j,val in enumerate(tmp):
            stat_mat[k][i][j]=val
            if(val==1):
                riped_list.append((k,i,j,0))#row,col,day
            elif(val==-1):
                visited[k][i][j]=1

def bfs():
    global m,n,h,stat_mat,riped_list,visited
    dx_list=[0,1,0,-1,0,0]
    dy_list=[1,0,-1,0,0,0]
    dz_list=[0,0,0,0,1,-1]
    max_date=0
    q=deque()    
    for height,row,col,day in riped_list:
        q.append((height,row,col,day))
    
    while q:
        parent=q.popleft()
        if(visited[parent[0]][parent[1]][parent[2]]==0):
            visited[parent[0]][parent[1]][parent[2]]=1
            max_date=max(max_date,parent[3])
            for dy,dx,dz in zip(dy_list,dx_list,dz_list):
                if(0<=parent[0]+dz<=(h-1) and 0<=parent[1]+dy<=(n-1) and 0<=parent[2]+dx<=(m-1) and visited[parent[0]+dz][parent[1]+dy][parent[2]+dx]==0):
                    q.append((parent[0]+dz,parent[1]+dy,parent[2]+dx,parent[3]+1))
    return max_date

def chck0(list_3d):
    h=len(list_3d)
    row=len(list_3d[0])
    col=len(list_3d[0][0])
    set1=set()
    for k in range(h):
        for i in range(row):
            for j in range(col):
                set1.add(list_3d[k][i][j])
    if 0 in set1:
        return True
    else:
        return False
    
ttt=bfs()

if(chck0(visited)):
    print(-1)
else:
    print(ttt)