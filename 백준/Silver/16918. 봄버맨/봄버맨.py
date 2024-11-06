import sys
input=sys.stdin.readline

r,c,n=map(int,input().split())
mat=[list(input().strip()) for _ in range(r)]

bombs=[]
for i in range(r):
    for j in range(c):
        if(mat[i][j]=='O'):bombs.append((i,j))
        
def bomb():
    global mat,bombs
    for i in bombs:
        y,x=i
        for dy,dx in [(1,0),(0,1),(-1,0),(0,-1),(0,0)]:
            ny,nx=y+dy,x+dx
            if(0<=ny<r and 0<=nx<c):
                mat[ny][nx]='.'
    return
def newbomb():
    global mat,bombs
    for i in range(r):
        for j in range(c):
            if(mat[i][j]=='.'):mat[i][j]='O'
    return

def bombUpdate():
    global mat,bombs
    bombs=[]
    for i in range(r):
        for j in range(c):
            if(mat[i][j]=='O'):bombs.append((i,j))
    return

time =1
while 1:
    if(time>=n):break
    newbomb()
    time+=1
    if(time>=n):break
    bomb()
    bombUpdate()
    time+=1
    if(time>=n):break
for line in mat:
    print(*line,sep='')