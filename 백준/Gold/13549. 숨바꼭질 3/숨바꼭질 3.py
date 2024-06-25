from collections import deque
inf=int(1e8)
n,m=map(int,input().split())
visited=[0]*100001
cost=[inf]*100001
def bfs(start):
    global n,m,visited,cost
    max_limit=100000
    func_list=[lambda x: x+1,lambda x: x-1]
    q=deque()
    q.append((start,0))
    visited[start]=1
    cost[start]=0
    while(q):
        parent=q.popleft() #(start,cost)
        tmp1=2*parent[0]
        tmp2=parent[1]
        while tmp1<=max_limit and tmp2<cost[tmp1]:
            #if(tmp2<cost[tmp1]):
                visited[tmp1]=1
                cost[tmp1]=tmp2
                q.append((tmp1,tmp2))
                tmp1*=2
        for func1 in func_list:
            if(0<=func1(parent[0])<=max_limit and parent[1]+1<cost[func1(parent[0])]):
                visited[func1(parent[0])]=1
                cost[func1(parent[0])]=parent[1]+1
                q.append((func1(parent[0]),parent[1]+1))
bfs(n)
print(cost[m])