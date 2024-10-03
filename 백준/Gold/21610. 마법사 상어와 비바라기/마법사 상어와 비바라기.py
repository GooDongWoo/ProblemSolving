dy_dx=[(0,-1),(-1,-1),(-1,0),(-1,1),(0,1),(1,1),(1,0),(1,-1)]
n,m=map(int,input().split())
a=[list(map(int,input().split())) for _ in range(n)]
querys=[tuple(map(int,input().split())) for _ in range(m)]
c=[[0]*n for _ in range(n)]
c[n-1][0]=c[n-1][1]=c[n-2][0]=c[n-2][1]=1

def cMove(d,s):
    global c,dy_dx,n
    tmp_c=[[0]*n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if(c[i][j]==1):
                ny,nx=(i+dy_dx[d-1][0]*s)%n,(j+dy_dx[d-1][1]*s)%n
                tmp_c[ny][nx]=1
    return tmp_c

def rain_delete():
    global c,a,n
    for i in range(n):
        for j in range(n):
            if(c[i][j]==1):
                a[i][j]+=1
                c[i][j]=0
                cl.append((i,j))
    return

def wDup():
    global cl,a,n
    for y,x in cl:
        cnt=0
        for dy,dx in [(-1,-1),(-1,1),(1,1),(1,-1)]:
            ny,nx=y+dy,x+dx
            if(0<=ny<n and 0<=nx<n and a[ny][nx]>0):
                cnt+=1
        a[y][x]+=cnt
    return 

def cMake():
    global c,a,n,cl
    s_cl=set(cl)
    for i in range(n):
        for j in range(n):
            if(a[i][j]>=2 and (i,j) not in s_cl):
                a[i][j]-=2
                c[i][j]=1
    

for d,s in querys:
    cl=[]
    c=cMove(d,s)
    rain_delete()
    wDup()
    cMake()

res=0
for i in range(n):
    for j in range(n):
        res+=a[i][j]
print(res)