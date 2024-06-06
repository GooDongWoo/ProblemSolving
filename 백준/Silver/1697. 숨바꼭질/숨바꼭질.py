import sys
from collections import deque

inf=int(1e8)
n,m=map(int,input().split())
visited=[0]*100001
cost=[inf]*100001

def bfs(start):
    global n,m,visited,cost
    func_list=[lambda x: 2*x,lambda x: x+1,lambda x: x-1]
    q=deque()
    q.append((start,0))
    while(q):
        parent=q.popleft() #(start,cost)
        if(visited[parent[0]]==0 and parent[1]<cost[parent[0]]):
            visited[parent[0]]=1
            cost[parent[0]]=parent[1]
            for func1 in func_list:
                if(0<=func1(parent[0])<=100000):
                    q.append((func1(parent[0]),parent[1]+1))
        
bfs(n)
print(cost[m])