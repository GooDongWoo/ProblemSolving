from collections import deque
import sys
n, m=map(int,sys.stdin.readline().split())
adj_m=[[] for _ in range(n+1)]
v=[0]*(n+1)
for _ in range(m):
    n1, n2=map(int,sys.stdin.readline().split())
    adj_m[n1].append(n2)
    adj_m[n2].append(n1)

def dfs(start):
    global n,m,adj_m,v
    q=deque()
    q.append(start)
    while q:
        p=q.pop()
        if(v[p]==0):
            v[p]=1
            for c in adj_m[p]:
                if(v[c]==0):
                    q.append(c)
    
cnt=0
for i in range(1,n+1):
    if v[i]==0:
        cnt+=1
        dfs(i)

sys.stdout.write(f'{cnt}')