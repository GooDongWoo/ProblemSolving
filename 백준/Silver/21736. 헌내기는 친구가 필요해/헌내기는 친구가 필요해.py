import sys
from collections import deque
row,col=map(int,input().split())
map1=[0]*row
for i in range(row):
    map1[i]=list(sys.stdin.readline().strip())
visited=[[0 for _ in range(col)] for _ in range(row)]
start_x=0
start_y=0
for i in range(row):
    for j in range(col):
        if(map1[i][j]=='I'):
            start_x=j
            start_y=i
            break
cnt=0
def dfs(sx,sy):
    global map1,row,col,cnt,visited
    dx=[0,0,1,-1]
    dy=[1,-1,0,0]
    stck1=deque()
    stck1.append((sx,sy))
    while(stck1):
        tmp=stck1.pop()
        if (visited[tmp[1]][tmp[0]]==0): #방문 안햇으면
            visited[tmp[1]][tmp[0]]=1
            if(map1[tmp[1]][tmp[0]]=='P'):
                cnt+=1
            for i in range(4):
                if((tmp[1]+dy[i]>=0 and tmp[1]+dy[i]<row) and (tmp[0]+dx[i]>=0 and tmp[0]+dx[i]<col) and (visited[tmp[1]+dy[i]][tmp[0]+dx[i]]==0) and (map1[tmp[1]+dy[i]][tmp[0]+dx[i]]!='X')):# 자손들이 캠퍼스 안에 있고 방문 안햇으면 스택 추가
                    stck1.append((tmp[0]+dx[i],tmp[1]+dy[i]))
                
            
dfs(start_x,start_y)
if(cnt==0):
    print('TT')
else:
    print(cnt)