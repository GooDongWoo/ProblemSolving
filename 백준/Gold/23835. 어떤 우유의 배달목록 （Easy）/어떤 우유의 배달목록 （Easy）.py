import sys
from collections import deque
sys.setrecursionlimit(int(1e8))

n=int(sys.stdin.readline())
adj_v=[[] for _ in range(n)]

for _ in range(n-1):
    a,b=map(int,sys.stdin.readline().split())
    adj_v[a-1].append(b-1)
    adj_v[b-1].append(a-1)
cnter=[0]*n

def dfs(start,end):
    global n,adj_v,cnter,log,v
    v[start]=1
    if(start==end):
        for idx,item in enumerate(list(log),1):
            cnter[item]+=idx
    else:
        for c in adj_v[start]:
            if(v[c]==0):
                log.append(c)
                dfs(c,end)
                log.pop()
    
q=int(sys.stdin.readline())
for _ in range(q):
    query=list(map(int,sys.stdin.readline().split()))
    if(query[0]==1):
        start,end=query[1]-1,query[2]-1
        log=deque()
        v=[0]*n
        dfs(start,end)
    else:
        target=query[1]-1
        sys.stdout.write(f'{cnter[target]}\n')