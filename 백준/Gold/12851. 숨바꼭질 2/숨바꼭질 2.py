from collections import deque
inf=int(1e8)
n,m=map(int,input().split())
visited=[0]*100001
cost=[inf]*100001
res=[]
def bfs(start,target):
    global n,m,visited,cost,res
    max_limit=100000
    func_list=[lambda x: 2*x,lambda x: x+1,lambda x: x-1]
    q=deque()
    q.append((start,0))
    visited[start]=1
    cost[start]=0
    while(q):
        parent=q.popleft() #(start,cost)
        if(parent[0]==target):
            res.append(parent)
        for func1 in func_list:
            if(0<=func1(parent[0])<=max_limit and parent[1]+1<=cost[func1(parent[0])]):
                visited[func1(parent[0])]=1
                cost[func1(parent[0])]=parent[1]+1
                q.append((func1(parent[0]),parent[1]+1))

bfs(n,m)
res.sort(key=lambda x:x[1])
cnt=0
tmp=res[0][1]
for i in range(len(res)):
    if(res[i][1]==tmp):
        cnt+=1
print(cost[m])
print(cnt)