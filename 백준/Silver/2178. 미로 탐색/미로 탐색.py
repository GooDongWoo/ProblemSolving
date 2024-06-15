import sys
from collections import deque
print = sys.stdout.write
input=sys.stdin.readline

N,M = map(int,input().split()) # row X col

visited=[[0 for _ in range(M)] for _ in range(N)]
cnt1=[[10000 for _ in range(M)] for _ in range(N)]

# adj_matrix initialize
adj_m=[[0 for _ in range(M)] for _ in range(N)]
for row in range(N): 
    tmp=input().strip()
    for idx,item in enumerate(tmp):
        adj_m[row][idx]=int(item)

#down,right,up,left (넣기전에 조건 확인하고) 각각 큐에 넣고 bfs해서 각 direction별로 최소의 거리를 계속 구한다.
def bfs(row,col,visited,cnt1):
    global adj_m,N,M
    #code
    visited[row][col]=1        
    que1=deque([(row,col)])
    cnt1[row][col]=1
    
    while(que1):
        tmp=que1.popleft()
        if(tmp==(N-1,M-1)):
            return cnt1[N-1][M-1]
        #down,
        if(tmp[0]+1<N):
            if(adj_m[tmp[0]+1][tmp[1]]==1 and visited[tmp[0]+1][tmp[1]]==0):
                que1.append((tmp[0]+1,tmp[1]))
                visited[tmp[0]+1][tmp[1]]=1
                cnt1[tmp[0]+1][tmp[1]]=min(cnt1[tmp[0]][tmp[1]]+1,cnt1[tmp[0]+1][tmp[1]])
        # right, 
        if(tmp[1]+1<M):
            if(adj_m[tmp[0]][tmp[1]+1]==1 and visited[tmp[0]][tmp[1]+1]==0):
                que1.append((tmp[0],tmp[1]+1))
                visited[tmp[0]][tmp[1]+1]=1
                cnt1[tmp[0]][tmp[1]+1]=min(cnt1[tmp[0]][tmp[1]]+1,cnt1[tmp[0]][tmp[1]+1])
        # up, 
        if(tmp[0]-1>-1):
            if(adj_m[tmp[0]-1][tmp[1]]==1 and visited[tmp[0]-1][tmp[1]]==0):
                que1.append((tmp[0]-1,tmp[1]))
                visited[tmp[0]-1][tmp[1]]=1
                cnt1[tmp[0]-1][tmp[1]]=min(cnt1[tmp[0]][tmp[1]]+1,cnt1[tmp[0]-1][tmp[1]])
        # left
        if(tmp[1]-1>-1):
            if(adj_m[tmp[0]][tmp[1]-1]==1 and visited[tmp[0]][tmp[1]-1]==0):
                que1.append((tmp[0],tmp[1]-1))
                visited[tmp[0]][tmp[1]-1]=1
                cnt1[tmp[0]][tmp[1]-1]=min(cnt1[tmp[0]][tmp[1]]+1,cnt1[tmp[0]][tmp[1]-1])

print(f'{bfs(0,0,visited,cnt1)}')
