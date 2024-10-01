n=int(input())
mat=[[-1]*n for _ in range(n)]
tot=n*n
fl=[[] for _ in range(tot)]
ord=[0]*tot
for i in range(tot):
    t,*f=map(lambda x: int(x)-1,input().split())
    fl[t]=f
    ord[i]=t

dy_dx=[(1,0),(0,1),(-1,0),(0,-1)]

def locating(idx):
    global mat,tot,fl,dy_dx
    candidates=[]#(-f_cnt, y, x)
    favors=fl[idx]
    for i in range(n):
        for j in range(n):
            if(mat[i][j]==-1):
                cnt=0
                zcnt=0
                for dy,dx in dy_dx:
                    ny,nx=i+dy,j+dx
                    if(0<=ny<n and 0<=nx<n):
                        if(mat[ny][nx] in favors):
                            cnt-=1
                        elif(mat[ny][nx]==-1):
                            zcnt-=1
                candidates.append((cnt,zcnt,i,j))
    candidates.sort(key=lambda x: (x[0],x[1],x[2],x[3]))
    _,_,ty,tx=candidates[0]
    mat[ty][tx]=idx
    return

for i in ord:
    locating(i)

res=0
for i in range(n):
    for j in range(n):
        favors=fl[mat[i][j]]
        cnt=0
        for dy,dx in dy_dx:
            ny,nx=i+dy,j+dx
            if(0<=ny<n and 0<=nx<n and mat[ny][nx] in favors):
                cnt+=1
        if(cnt==0):
            res+=0
        else:
            res+=10**(cnt-1)
print(res)