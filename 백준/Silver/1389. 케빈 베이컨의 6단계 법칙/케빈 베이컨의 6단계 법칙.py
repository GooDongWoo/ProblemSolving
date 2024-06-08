import sys
from collections import deque

inf=int(1e8)
n,m=map(int,sys.stdin.readline().split())
adj_LL=[[] for _ in range(n+1)]
kevin_num_list=[inf]*(n+1)

for _ in range(m):
    f1,f2=map(int,sys.stdin.readline().split())
    adj_LL[f1].append(f2)
    adj_LL[f2].append(f1)
    
def findKevinNum(start):
    global n,m,adj_LL,kevin_num_list,inf
    n_th_relat=[inf]*(n+1)
    q=deque()
    q.append((start,0))
    n_th_relat[start]=0
    while q:
        parent=q.popleft()
        for child in adj_LL[parent[0]]:
            if(n_th_relat[child]==inf):
                n_th_relat[child]=parent[1]+1
                q.append((child,parent[1]+1))            
    kevin_num_list[start]=sum(n_th_relat)
    
for i in range(1,n+1):
    findKevinNum(i)

print(kevin_num_list.index(min(kevin_num_list[1:])))