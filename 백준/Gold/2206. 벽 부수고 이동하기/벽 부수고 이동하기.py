import sys
from collections import deque
n,m=map(int,sys.stdin.readline().split())
map_mat=[list(map(int,list(sys.stdin.readline().rstrip()))) for _ in range(n)]
inf=int(1e8)
def bfs(start=(0,0,0,1)):# row,col,crush,cost
    global n,m,map_mat
    dy_dx_list=[[1,0],[0,1],[-1,0],[0,-1]]
    visited=[[[0 for _ in range(2)] for _ in range(m)] for _ in range(n)]# n*m*2
    cost=[[[inf for _ in range(2)] for _ in range(m)] for _ in range(n)]# n*m*2
    q=deque([start])
    visited[0][0][0]=1
    cost[0][0][0]=start[3]
    while q:
        parent=q.popleft()
        if(parent[0]==n-1 and parent[1]==m-1):
            break
        for dy,dx in dy_dx_list:#안부신 방문-> 부실 경우도 고려(전방위 쌉가능),
            if(0<=dy+parent[0]<n and 0<=dx+parent[1]<m and parent[2]==0 and visited[parent[0]+dy][parent[1]+dx][0]==0):
                if(map_mat[dy+parent[0]][dx+parent[1]]==1):#노크러시이고 부셔야 갈 수 있는 경우
                    q.append((dy+parent[0],dx+parent[1],1,parent[3]+1))
                    visited[dy+parent[0]][dx+parent[1]][1]=1
                    cost[dy+parent[0]][dx+parent[1]][1]=parent[3]+1

                else:#노 크러시지만 안부셔도 갈 수 잇음
                    q.append((dy+parent[0],dx+parent[1],0,parent[3]+1))
                    visited[dy+parent[0]][dx+parent[1]][0]=1
                    cost[dy+parent[0]][dx+parent[1]][0]=parent[3]+1

            elif(0<=dy+parent[0]<n and 0<=dx+parent[1]<m and parent[2]==1 and visited[parent[0]+dy][parent[1]+dx][1]==0 and map_mat[parent[0]+dy][parent[1]+dx]==0 and cost[parent[0]+dy][parent[1]+dx][0]>parent[3]+1):#부신 방문은 -> map보고 1이면 못가고 visited
                q.append((dy+parent[0],dx+parent[1],1,parent[3]+1))
                visited[dy+parent[0]][dx+parent[1]][1]=1
                cost[dy+parent[0]][dx+parent[1]][1]=parent[3]+1
            else:
                pass
    return min(cost[n-1][m-1])

tmp=bfs()
if(tmp==inf):
    print(-1)
else:
    print(tmp)