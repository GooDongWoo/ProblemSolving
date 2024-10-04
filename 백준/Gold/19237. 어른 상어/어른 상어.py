dy_dx=[(-1,0),(1,0),(0,-1),(0,1)]
n,m,k=map(int,input().split())
mat=[list(map(int,input().split())) for _ in range(n)]
ds=list(map(lambda x:int(x)-1,input().split()))#위,아래,왼,오
pds=[[list(map(lambda x: int(x)-1,input().split())) for _ in range(4)] for _ in range(m)]#위,아래,왼,오
for i in range(n):
    for j in range(n):
        if(mat[i][j]):
            mat[i][j]=(k,mat[i][j])

def move():
    global dy_dx,n,k,mat,ds,pds
    tmp=[[0]*n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if(mat[i][j]):
                if(tmp[i][j]):continue
                if(mat[i][j][0]==k):
                    #move
                    c1=[]
                    c2=[]
                    d=ds[mat[i][j][1]-1]
                    for idx in pds[mat[i][j][1]-1][d]:#list
                        dy,dx=dy_dx[idx]
                        ny,nx=i+dy,j+dx
                        if(0<=ny<n and 0<=nx<n):
                            if(mat[ny][nx]==0):
                                c1.append(idx)
                            elif(mat[ny][nx][1]==mat[i][j][1]):
                                c2.append(idx)
                    
                    if(c1):
                        ny,nx=i+dy_dx[c1[0]][0],j+dy_dx[c1[0]][1]
                        idx=c1[0]
                    else:
                        ny,nx=i+dy_dx[c2[0]][0],j+dy_dx[c2[0]][1]
                        idx=c2[0]
                    
                    if not (tmp[ny][nx] and tmp[ny][nx][0]==k and tmp[ny][nx][1]<mat[i][j][1]):
                        tmp[ny][nx]=(k,mat[i][j][1])
                        ds[mat[i][j][1]-1]=idx
                tmp[i][j]=(mat[i][j][0]-1,mat[i][j][1]) if mat[i][j][0]>1 else 0

    mat=tmp
    cnter=0
    for i in range(n):
        for j in range(n):
            if(mat[i][j] and mat[i][j][0]==k):cnter+=1
    return 1 if cnter!=1 else 0

for i in range(1,1001):
    if not (move()):
        print(i)
        exit()
print(-1)