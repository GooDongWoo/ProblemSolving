import sys
from collections import deque
n=int(input())
k=int(input())
adj_m=[[0 for _ in range(n)] for _ in range(n)]
visit=[0]*n


for _ in range(k):
    a,b=map(int,sys.stdin.readline().split())
    adj_m[a-1][b-1]=1
    adj_m[b-1][a-1]=1

def dfs(start):
    global adj_m,visit
    stck1=deque([start-1])
    while(stck1):
        tmp=stck1.pop()
        visit[tmp]=1
        for child,child_val in enumerate(adj_m[tmp]):
            if(child_val==1):
                if(visit[child]==0):
                    stck1.append(child)
                    
dfs(1)
print(sum(visit)-1)