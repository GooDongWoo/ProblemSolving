def makeshop(row,col,d):#하우상좌
    global mat,n,m
    mat[row][col]='#'
    if(d==0):
        while 0<=row+1<n and (mat[row+1][col]==0 or mat[row+1][col]=='#'):
            mat[row+1][col]='#'
            row+=1
    elif (d==1):
        while 0<=col+1<m and (mat[row][col+1]==0 or mat[row][col+1]=='#'):
            mat[row][col+1]='#'
            col+=1
    elif (d==2):
        while 0<=row-1<n and (mat[row-1][col]==0 or mat[row-1][col]=='#'):
            mat[row-1][col]='#'
            row-=1
    elif (d==3):
        while 0<=col-1<m and (mat[row][col-1]==0 or mat[row][col-1]=='#'):
            mat[row][col-1]='#'
            col-=1

def see(row,col,t,d):
    if t==1:
        makeshop(row,col,d)
    elif t==2:
        makeshop(row,col,d)
        makeshop(row,col,(d+2)%4)
    elif t==3:
        makeshop(row,col,d)
        makeshop(row,col,(d+1)%4)
    elif t==4:
        makeshop(row,col,d)
        makeshop(row,col,(d+1)%4)
        makeshop(row,col,(d+2)%4)
    elif t==5:
        makeshop(row,col,d)
        makeshop(row,col,(d+1)%4)
        makeshop(row,col,(d+2)%4)
        makeshop(row,col,(d+3)%4)


import sys
n,m=map(int,sys.stdin.readline().split())
origin=[list(map(int,sys.stdin.readline().split())) for _ in range(n)]
cctv=[]
cctv_cnter=0
for i in range(n):
    for j in range(m):
        if(origin[i][j]==1):cctv.append((i,j,1)); origin[i][j]=0;cctv_cnter+=1
        elif(origin[i][j]==2):cctv.append((i,j,2)); origin[i][j]=0;cctv_cnter+=1
        elif(origin[i][j]==3):cctv.append((i,j,3)); origin[i][j]=0;cctv_cnter+=1
        elif(origin[i][j]==4):cctv.append((i,j,4)); origin[i][j]=0;cctv_cnter+=1
        elif(origin[i][j]==5):cctv.append((i,j,5)); origin[i][j]=0;cctv_cnter+=1
        else:pass
cases=[]
t_case=[0]*cctv_cnter
def cb(idx):
    if(idx==cctv_cnter):
        cases.append(t_case.copy())
    else:
        for i in range(4):
            t_case[idx]=i
            cb(idx+1)
cb(0)

result=[]
for cmds in cases: #each directions
    mat=[v.copy() for v in origin]
    for idx,cmd in enumerate(cmds):
        row,col,types=cctv[idx]
        see(row,col,types,cmd)
    squarearea=0
    for i in range(n):
        for j in range(m):
            if(mat[i][j]==0):squarearea+=1
    result.append(squarearea)
print(min(result))