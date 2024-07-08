import sys
from collections import deque
n,m=map(int,sys.stdin.readline().split())
visited=[0]*n
res=[0]*m
def dfs(num=0,idx=0):
    global n,m,visited
    res[idx]=num+1
    visited[num]=1
    if(idx==m-1):
        print(*res)
    else:
        for i in range(n):
            if(not visited[i]):
                dfs(i,idx+1)
                visited[i]=0
for i in range(n):
    dfs(i)
    visited=[0]*n
    res=[0]*m