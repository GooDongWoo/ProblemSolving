import sys
from collections import deque
n,m=map(int,sys.stdin.readline().split())
map_mat=[list(map(int,list(sys.stdin.readline().rstrip()))) for _ in range(n)]
inf=int(1e8)
def bfs(start=(0,0,0,1)):# row,col,crush,cost
    global n,m,map_mat
    dy_dx_list=[[1,0],[0,1],[-1,0],[0,-1]]
    vstd=[[[0 for _ in range(2)] for _ in range(m)] for _ in range(n)]# n*m*2
    q=deque([start])
    vstd[0][0][0]=1
    while q:
        p=q.popleft()
        if(p[0]==n-1 and p[1]==m-1):
            print(p[3])
            return
        for dy,dx in dy_dx_list:#안부신 방문-> 부실 경우도 고려(전방위 쌉가능),
            if(0<=dy+p[0]<n and 0<=dx+p[1]<m and p[2]==0 and vstd[p[0]+dy][p[1]+dx][0]==0):
                if(map_mat[dy+p[0]][dx+p[1]]==1):#노크러시이고 부셔야 갈 수 있는 경우
                    q.append((dy+p[0],dx+p[1],1,p[3]+1))
                    vstd[dy+p[0]][dx+p[1]][1]=1
                    vstd[dy+p[0]][dx+p[1]][0]=1

                else:#노 크러시지만 안부셔도 갈 수 잇음
                    q.append((dy+p[0],dx+p[1],0,p[3]+1))
                    vstd[dy+p[0]][dx+p[1]][0]=1

            elif(0<=dy+p[0]<n and 0<=dx+p[1]<m and p[2]==1 and vstd[p[0]+dy][p[1]+dx][1]==0 and map_mat[p[0]+dy][p[1]+dx]==0 ):#부신 방문은 -> map보고 1이면 못가고 vstd
                q.append((dy+p[0],dx+p[1],1,p[3]+1))
                vstd[dy+p[0]][dx+p[1]][1]=1
            else:
                pass
    print(-1)
    return 
bfs()
