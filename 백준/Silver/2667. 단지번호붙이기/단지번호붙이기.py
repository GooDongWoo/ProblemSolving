import sys
from collections import deque

n=int(input().rstrip())
stat_mat=[[0 for _ in range(n)] for _ in range(n)]
visited=[[1 for _ in range(n)] for _ in range(n)]
cnt_list=[]
set1=set()
for i in range(n):
    tmp=list(map(int,list(sys.stdin.readline().rstrip())))
    for j in range(n):
        stat_mat[i][j]=tmp[j]
        if(tmp[j]==1):
            set1.add((i,j))
            visited[i][j]=0

def bfs():
    global n,stat_mat,set1,visited
    q=deque()
    dy_list=[1,0,-1,0]
    dx_list=[0,1,0,-1]
    if not (len(set1)):
        return 0
    tmp=set1.pop()
    q.append(tmp)
    visited[tmp[0]][tmp[1]]=1
    cnt=0
    while q:
        parent=q.popleft()
        cnt+=1
        for dy,dx in zip(dy_list,dx_list):
            if(0<=parent[0]+dy<=(n-1) and 0<=parent[1]+dx<=(n-1) and visited[parent[0]+dy][parent[1]+dx]==0):
                q.append((parent[0]+dy,parent[1]+dx))
                visited[parent[0]+dy][parent[1]+dx]=1
                set1.remove((parent[0]+dy,parent[1]+dx))
    return cnt

while 1:
    tmp=bfs()
    if(tmp): 
        cnt_list.append(tmp)
    else:
        break

cnt_list.sort()
print(len(cnt_list))
print(*cnt_list,sep='\n')
