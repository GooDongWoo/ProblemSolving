import sys
input=sys.stdin.readline
INF=int(1e9)
t=int(input())
for _ in range(t):
    n,m,w=map(int,input().split())
    adj_v=[[] for _ in range(n)]
    adj_mat=[[INF]*n for _ in range(n)]
    
    dist=[INF]*n
    dist[0]=0
    for _ in range(m):
        a,b,c=map(int,input().split())
        a-=1;b-=1
        adj_mat[a][b]=min(adj_mat[a][b],c)
        adj_mat[b][a]=min(adj_mat[b][a],c)
    for _ in range(w):
        a,b,c=map(int,input().split())
        a-=1;b-=1
        adj_mat[a][b]=min(adj_mat[a][b],-c)

    for i in range(n):
        for j in range(n):
            if adj_mat[i][j]<INF:
                adj_v[i].append((j,adj_mat[i][j]))#(end,weight)

    for _ in range(n-1):
        for start in range(n):
            for edge in adj_v[start]:
                end,weight=edge
                dist[end]=min(dist[end],dist[start]+weight)
    
    minusF=0
    for start in range(n):
        for edge in adj_v[start]:
            end,weight=edge
            if(dist[end]>dist[start]+weight):minusF=1
    
    if minusF:print('YES')
    else:print('NO')