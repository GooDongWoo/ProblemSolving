import sys
input=sys.stdin.readline
INF=int(1e8)
n,m=map(int,input().split())
k,c=map(int,input().split())
mat=[list(input().rstrip()) for _ in range(n)]
dys=[0,1,-1,0,0]
dxs=[0,0,0,1,-1]

homes=[]
start=0
for i in range(n):
    for j in range(m):
        if(mat[i][j]=='S'):
            start=(i,j)
            break
    if(start):break

v=[[INF]*m for _ in range(n)]
q=[(start[0],start[1],0)]
v[start[0]][start[1]]=0
t = 0
while q:
    q_n = []
    for y,x,dc in q:
        if(mat[y][x]=='E'):
            print(t)
            exit()
        for i in range(5):
            ny,nx=dys[i]+y,dxs[i]+x
            if(0<=ny<n and 0<=nx<m and (mat[ny][nx]!='#')):
                hn = dc + (c if (mat[ny][nx]=='.' or mat[ny][nx]=='E') else -k)
                if hn >= 100:
                    continue
                if hn < 0:
                    hn = 0
                if(hn<v[ny][nx]):
                    v[ny][nx]=hn
                    q_n.append((ny,nx,hn))
    q=q_n
    t+=1
print(-1)
