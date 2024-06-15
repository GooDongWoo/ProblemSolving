import sys
from collections import deque
inf=int(1e8)
n,m=map(int,sys.stdin.readline().split())
ladder_dict=dict()
snake_dict=dict()
cost_list=[inf for _ in range(101)]

for _ in range(n):
    start,end=map(int,sys.stdin.readline().split())
    ladder_dict[start]=end

for _ in range(m):
    start,end=map(int,sys.stdin.readline().split())
    snake_dict[start]=end

def newBFS():
    global inf,cost_list
    q=deque()
    q.append((0,1)) #(cnt, cur_num)
    while q:
        parent=q.popleft()
        if(parent[0]<cost_list[parent[1]]):
            cost_list[parent[1]]=parent[0]
            if(parent[1]==100):
                break
            for i in range(6,0,-1):
                if(parent[1]+i<101):
                    if(not(parent[1]+i in snake_dict) and not (parent[1]+i in ladder_dict) and parent[0]+1 < cost_list[parent[1]+i]):
                        q.append((parent[0]+1,parent[1]+i))
                    elif ((parent[1]+i in ladder_dict) and parent[0]+1 < cost_list[ladder_dict[parent[1]+i]]):
                        q.append((parent[0]+1,ladder_dict[parent[1]+i]))
                    elif ((parent[1]+i in snake_dict) and parent[0]+1 < cost_list[snake_dict[parent[1]+i]]):
                        q.append((parent[0]+1,snake_dict[parent[1]+i]))

newBFS()
print(cost_list[100])