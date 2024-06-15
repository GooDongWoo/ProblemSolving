import sys
sys.setrecursionlimit(10**7)
n=int(input())
adj_m=[[] for _ in range(n)]
for _ in range(n-1):
    a,b,w=map(int,sys.stdin.readline().split())
    adj_m[a-1].append((b-1,w))
    adj_m[b-1].append((a-1,w))
visited=[0 for _ in range(n)]
max_w=0
last_node=-1

def dfs(node_num,cw):
    global adj_m,max_w,last_node,visited
    if(cw>max_w):
        max_w=cw
        last_node=node_num
    visited[node_num]=1
    for child_num,w in adj_m[node_num]:
        if(w!=0):
            if(visited[child_num]==0):
                dfs(child_num,cw+w)
    visited[node_num]=0

dfs(0,0)
visited=[0 for _ in range(n)]
dfs(last_node,0)
print(max_w)