import sys
input=sys.stdin.readline

INF=int(1e9)
n=int(input())
m=int(input())
adj_v=[[INF]*n for _ in range(n)]
for i in range(n):
    adj_v[i][i]=0
    
for _ in range(m):
    a,b,w=map(int,input().split())
    adj_v[a-1][b-1]=min(adj_v[a-1][b-1],w)

for must in range(n):
    for start in range(n):
        for end in range(n):
            adj_v[start][end]=min(adj_v[start][end],adj_v[start][must]+adj_v[must][end])

for i in range(n):
    for j in range(n):
        if(adj_v[i][j]>=INF):
            adj_v[i][j]=0
        sys.stdout.write(f'{adj_v[i][j]} ')
    sys.stdout.write(f'\n')