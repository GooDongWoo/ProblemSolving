import sys
from collections import deque

def dfs(start):
    global n,m,v,adjv,cnter
    if(v[start]):return
    stck=deque()
    stck.append(start)
    t_flag=1
    while stck:
        p=stck.pop()
        if(v[p]==0):
            v[p]=1
            for c in adjv[p]:
                if(v[c]==0):
                    stck.append(c)
        else:
            t_flag=0
    cnter+=t_flag
    return

t_idx=1
while 1:
    n,m=map(int,sys.stdin.readline().split())
    if(n==0 and m==0):break
    v=[0]*(n)
    adjv=[[] for _ in range(n)]
    for _ in range(m):
        a,b=map(int,sys.stdin.readline().split())
        adjv[a-1].append(b-1)
        adjv[b-1].append(a-1)
    cnter=0
    for i in range(n):
        dfs(i)
    if(cnter>1):
        sys.stdout.write(f'Case {t_idx}: A forest of {cnter} trees.\n')
    elif(cnter==1):
        sys.stdout.write(f'Case {t_idx}: There is one tree.\n')
    else:
        sys.stdout.write(f'Case {t_idx}: No trees.\n')
    t_idx+=1