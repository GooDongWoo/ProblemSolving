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
''' # 그냥 queue써서 쌉노가다 돌리는게 나을듯
#도착하는데 걸리는 코스트(1~6으로만 갈때 or 뱀으로 내려올때 )
#근데 만약 뱀에서 내려올때는 뱀에서의 최적화된 코스트를 모르지 않나? 대충 포문 10번 돌리면 되려나???

#만약 여기서 올라가는 게 있으면 올라가는 곳에 코스트 적용(사다리)
# for i in range(1,101):
#     tmp=inf
#     if(i in snake_dict):
        
#     cost_list[i]=min(cost_list[i],tmp)

'''