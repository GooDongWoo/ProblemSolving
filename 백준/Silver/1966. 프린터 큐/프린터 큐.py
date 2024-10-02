from collections import deque
import sys
input=sys.stdin.readline
t=int(input())
for _ in range(t):
    n,m=map(int,input().split())
    ps=list(map(int,input().split()))
    ps=[(ps[i],i) for i in range(n)]
    q=deque(ps)
    
    ps=sorted(ps,reverse=True)
    pdx=0
    cnt=0
    while q:
        p,idx=q.popleft()
        if(ps[pdx][0]==p):
            pdx+=1
            cnt+=1
            if(idx==m):
                print(cnt)
                break
        else:
            q.append((p,idx))