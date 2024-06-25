import sys
from collections import deque

inf=int(1e8)
n,m=map(int,input().split())
visited=[0]*100001
cost=[inf]*100001

def bfs(start):
    global n,m,visited,cost
    max_limit=100000
    func_list=[lambda x: 2*x,lambda x: x+1,lambda x: x-1]
    q=deque()
    q.append((start,0))
    visited[start]=1
    cost[start]=0
    while(q):
        parent=q.popleft() #(start,cost)
        for func1 in func_list:
            if(0<=func1(parent[0])<=max_limit and parent[1]+1<=cost[func1(parent[0])]):
                visited[func1(parent[0])]=1
                cost[func1(parent[0])]=parent[1]+1
                q.append((func1(parent[0]),parent[1]+1))

bfs(n)
end=m
res=[m]
while end!=n:
    if(not end&1 and cost[end//2]==cost[end]-1):
        end//=2
        res.append(end)
    elif(cost[end-1]==cost[end]-1):
        end-=1
        res.append(end)
    else:
        end+=1
        res.append(end)
print(cost[m])
print(*res[::-1])