from collections import deque
r,c,k=map(int,input().split())
mat=[list(map(int,input().split())) for _ in range(r)]
temp=[[0]*c for _ in range(r)]
fs=[]
detect=[]
for i in range(r):
    for j in range(c):
        if(mat[i][j]):
            if(mat[i][j]==5):
                detect.append((i,j))
                mat[i][j]=0
            else:
                fs.append((mat[i][j],i,j))
w=int(input())
ws=[[[0]*4 for _ in range(c)] for _ in range(r)]
for i in range(w):
    y,x,t=map(int,input().split())
    y,x=y-1,x-1
    if(t==0):
        ws[y][x][2]=1
        if(0<=y-1<r):
            ws[y-1][x][0]=1
    else:
        ws[y][x][1]=1
        if(0<=x+1<c):
            ws[y][x+1][3]=1

def chck():
    global k,detect
    for i,j in detect:
        if(temp[i][j]<k): return 0
    return 1

def wind():
    global temp,r,c,k,fs
    for w in fs:
        n_temp=[[0]*c for _ in range(r)]
        b,sy,sx=w
        if(b==1):
            if(ws[sy][sx][1]==0 and 0<=sx+1 <c):
                q=deque()
                q.append((sy,sx+1,5))
                n_temp[sy][sx+1]=5
                while q:
                    y,x,val=q.popleft()
                    if(val==0):break
                    #위 오
                    if(0<=y-1<r and 0<=x+1<c and (ws[y-1][x][0]==0) and (ws[y-1][x][1]==0)):
                        q.append((y-1,x+1,val-1))
                        n_temp[y-1][x+1]=val-1
                    #오
                    if(0<=y<r and 0<=x+1<c and (ws[y][x][1]==0)):
                        q.append((y,x+1,val-1))
                        n_temp[y][x+1]=val-1
                    #아 오
                    if(0<=y+1<r and 0<=x+1<c and (ws[y+1][x][2]==0) and (ws[y+1][x][1]==0)):
                        q.append((y+1,x+1,val-1))
                        n_temp[y+1][x+1]=val-1
        elif(b==2):
            if(ws[sy][sx][3]==0 and 0<=sx-1 <c):
                q=deque()
                q.append((sy,sx-1,5))
                n_temp[sy][sx-1]=5
                while q:
                    y,x,val=q.popleft()
                    if(val==0):break
                    #위 오
                    if(0<=y-1<r and 0<=x-1<c and (ws[y-1][x][0]==0) and (ws[y-1][x][3]==0)):
                        q.append((y-1,x-1,val-1))
                        n_temp[y-1][x-1]=val-1
                    #오
                    if(0<=y<r and 0<=x-1<c and (ws[y][x][3]==0)):
                        q.append((y,x-1,val-1))
                        n_temp[y][x-1]=val-1
                    #아 오
                    if(0<=y+1<r and 0<=x-1<c and (ws[y+1][x][2]==0) and (ws[y+1][x][3]==0)):
                        q.append((y+1,x-1,val-1))
                        n_temp[y+1][x-1]=val-1
        elif(b==3):
            if(ws[sy][sx][2]==0 and 0<=sy-1 <r):
                q=deque()
                q.append((sy-1,sx,5))
                n_temp[sy-1][sx]=5
                while q:
                    y,x,val=q.popleft()
                    if(val==0):break
                    #위 오
                    if(0<=y-1<r and 0<=x-1<c and (ws[y][x-1][1]==0) and (ws[y][x-1][2]==0)):
                        q.append((y-1,x-1,val-1))
                        n_temp[y-1][x-1]=val-1
                    #오
                    if(0<=y-1<r and 0<=x<c and (ws[y][x][2]==0)):
                        q.append((y-1,x,val-1))
                        n_temp[y-1][x]=val-1
                    #아 오
                    if(0<=y-1<r and 0<=x+1<c and (ws[y][x+1][2]==0) and (ws[y][x+1][3]==0)):
                        q.append((y-1,x+1,val-1))
                        n_temp[y-1][x+1]=val-1
        else:
            if(ws[sy][sx][0]==0 and 0<=sy+1 <r):
                q=deque()
                q.append((sy+1,sx,5))
                n_temp[sy+1][sx]=5
                while q:
                    y,x,val=q.popleft()
                    if(val==0):break
                    #위 오
                    if(0<=y+1<r and 0<=x-1<c and (ws[y][x-1][1]==0) and (ws[y][x-1][0]==0)):
                        q.append((y+1,x-1,val-1))
                        n_temp[y+1][x-1]=val-1
                    #오
                    if(0<=y+1<r and 0<=x<c and (ws[y][x][0]==0)):
                        q.append((y+1,x,val-1))
                        n_temp[y+1][x]=val-1
                    #아 오
                    if(0<=y+1<r and 0<=x+1<c and (ws[y][x+1][0]==0) and (ws[y][x+1][3]==0)):
                        q.append((y+1,x+1,val-1))
                        n_temp[y+1][x+1]=val-1
        for i in range(r):
            for j in range(c):
                temp[i][j]+=n_temp[i][j]

def temp_op():
    global temp,r,c,k,ws
    n_temp=[[0]*c for _ in range(r)]
    dy_dx=[(1,0),(0,1),(-1,0),(0,-1)]
    for i in range(r):
        for j in range(c):
            val=temp[i][j]
            for idx in range(4):
                if(ws[i][j][idx]):continue
                ny,nx=i+dy_dx[idx][0],j+dy_dx[idx][1]
                if(0<=ny<r and 0<=nx<c):
                    tmp=1 if temp[ny][nx]-temp[i][j]>=0 else -1
                    val+=(abs(temp[ny][nx]-temp[i][j])//4)*tmp
            n_temp[i][j]=val
    temp=n_temp
    return

def temp_down():
    global temp,r,c,k
    for i in range(c):
        temp[0][i]=max(0,temp[0][i]-1)
    for i in range(c):
        temp[r-1][i]=max(0,temp[r-1][i]-1)
    for i in range(1,r-1):
        temp[i][0]=max(0,temp[i][0]-1)
    for i in range(1,r-1):
        temp[i][c-1]=max(0,temp[i][c-1]-1)
    return

for choco in range(1,101):
    wind()
    temp_op()
    temp_down()
    if(chck()):
        print(choco)
        exit()
print(101)