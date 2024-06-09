import sys
from collections import deque

n=int(input())
stat_mat=[[0 for _ in range(n)] for _ in range(n)]
r_list=set()
g_list=set()
b_list=set()
for i in range(n):
    tmp=list(sys.stdin.readline().rstrip())
    for j in range(n):
        stat_mat[i][j]=tmp[j]
        if(tmp[j]=='R'):
            r_list.add((i,j))
        elif(tmp[j]=='G'):
            g_list.add((i,j))
        else:
            b_list.add((i,j))

def bfs1():
    global n,r_list,g_list,b_list,rgb_list,stat_mat
    rgb_list=[r_list.copy(),g_list.copy(),b_list.copy()]
    dy_list=[1,0,-1,0]
    dx_list=[0,1,0,-1]
    color_dict={'R':0,'G':1,'B':2}
    cnt=0
    for i in range(len(rgb_list)):
        visited=[[0 for _ in range(n)] for _ in range(n)]
        while rgb_list[i]:
            cnt+=1
            q=deque()
            set_top1=rgb_list[i].pop()
            q.append(set_top1)
            visited[set_top1[0]][set_top1[1]]=1
            while q:
                parent=q.popleft()
                for dy,dx in zip(dy_list,dx_list):
                    if(0<=parent[0]+dy<=(n-1) and 0<=parent[1]+dx<=(n-1) and color_dict[stat_mat[parent[0]+dy][parent[1]+dx]]==color_dict[stat_mat[set_top1[0]][set_top1[1]]] and visited[parent[0]+dy][parent[1]+dx]==0):
                        q.append((parent[0]+dy,parent[1]+dx))
                        visited[parent[0]+dy][parent[1]+dx]=1
                        rgb_list[i].remove((parent[0]+dy,parent[1]+dx))
    return cnt

def bfs2():
    global n,r_list,g_list,b_list,rgb_list,stat_mat
    rgb_list=[r_list.copy().union(g_list.copy()),b_list.copy()]
    dy_list=[1,0,-1,0]
    dx_list=[0,1,0,-1]
    color_dict={'R':0,'G':0,'B':2}
    cnt=0
    for i in range(len(rgb_list)):
        visited=[[0 for _ in range(n)] for _ in range(n)]
        while rgb_list[i]:
            cnt+=1
            q=deque()
            set_top1=rgb_list[i].pop()
            q.append(set_top1)
            visited[set_top1[0]][set_top1[1]]=1
            while q:
                parent=q.popleft()
                for dy,dx in zip(dy_list,dx_list):
                    if(0<=parent[0]+dy<=(n-1) and 0<=parent[1]+dx<=(n-1) and color_dict[stat_mat[parent[0]+dy][parent[1]+dx]]==color_dict[stat_mat[set_top1[0]][set_top1[1]]] and visited[parent[0]+dy][parent[1]+dx]==0):
                        q.append((parent[0]+dy,parent[1]+dx))
                        visited[parent[0]+dy][parent[1]+dx]=1
                        rgb_list[i].remove((parent[0]+dy,parent[1]+dx))
    return cnt
print(bfs1(),bfs2())