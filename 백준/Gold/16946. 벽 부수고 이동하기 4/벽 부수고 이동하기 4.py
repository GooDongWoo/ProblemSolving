import sys
from collections import deque
def bfs_cnt(start):
    global n,m,state_mat,root_mat,root_area_cnter,dydx
    q=deque()
    q.append(start)
    visited[start[0]][start[1]]=1
    root_mat[start[0]][start[1]]=start
    cnt=1
    while q:
        parent=q.popleft()
        for dy,dx in dydx:
            if(0<=parent[0]+dy<n and 0<=parent[1]+dx<m and visited[parent[0]+dy][parent[1]+dx]==0 and state_mat[parent[0]+dy][parent[1]+dx]=='0'):
                visited[parent[0]+dy][parent[1]+dx]=1
                root_mat[parent[0]+dy][parent[1]+dx]=start
                q.append((parent[0]+dy,parent[1]+dx))
                cnt+=1
    root_area_cnter[start]=cnt

n,m=map(int,sys.stdin.readline().split())
state_mat=[0 for _ in range(n)]
dydx=[(1,0),(0,1),(-1,0),(0,-1)]
#0인 좌표를 set에 추가
for i in range(n):
    state_mat[i]=list(sys.stdin.readline().rstrip())
#0인 좌표들에서 한 영역에 있으면 root를 정하고 그 root에다가 따로 거기에 연결된 개수를 작성한다. 
#1인 것들에서 +1되어있는 상태(본인)에서 상하좌우를 돌아보며 연결된 개수를 센다.
visited=[[0]*m for _ in range(n)]
root_mat=[[0]*m for _ in range(n)]
root_area_cnter=dict()
for x in range(n):
    for y in range(m):
        if state_mat[x][y] == '0' and not visited[x][y]:
            bfs_cnt((x, y))
            
ans_mat=[['0']*m for _ in range(n)]

for i in range(n):
    for j in range(m):
        if(state_mat[i][j]=='1'):
            cnter1=1
            tmp_set=set()
            for dy,dx in dydx:
                if(0<=i+dy<n and 0<=j+dx<m and state_mat[i+dy][j+dx]=='0'):
                    tmp_set.add(root_mat[i+dy][j+dx])
            for direction in tmp_set:
                cnter1+=root_area_cnter[direction]
            ans_mat[i][j]=str(cnter1%10)

for i in ans_mat:
    sys.stdout.write(f'{"".join(i)}\n')