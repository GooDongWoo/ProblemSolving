import sys
input=sys.stdin.readline

INF=int(1e9)
n,m,r=map(int,input().split())
items=list(map(int,input().split()))
adj_mat=[[INF]*n for _ in range(n)]
for i in range(n):
    adj_mat[i][i]=0

for _ in range(r):
    start,end,w=map(int,input().split())
    start-=1;end-=1
    adj_mat[start][end]=min(adj_mat[start][end],w)
    adj_mat[end][start]=min(adj_mat[end][start],w)

for i in range(n):
    for start in range(n):
        for end in range(n):
            if start==end:continue
            adj_mat[start][end]=min(adj_mat[start][end],adj_mat[start][i]+adj_mat[i][end])
            adj_mat[end][start]=min(adj_mat[end][start],adj_mat[end][i]+adj_mat[i][start])

res=0
for start in range(n):
    tmp=0
    for end in range(n):
        if(adj_mat[start][end]<=m):
            tmp+=items[end]
    res=max(res,tmp)
print(res)