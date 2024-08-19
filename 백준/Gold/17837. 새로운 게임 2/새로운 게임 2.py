import sys
n,k=map(int,sys.stdin.readline().split())
mat=[list(map(int,sys.stdin.readline().split())) for _ in range(n)]
stcks=[[[] for _ in range(n)] for _ in range(n)]
units=[0]*k
dy_dx=[(0,1),(0,-1),(-1,0),(1,0)]
for i in range(k):
    r,c,dir=map(int,sys.stdin.readline().split())
    units[i]=[r-1,c-1,dir-1]
    stcks[r-1][c-1].append(i)

def redwhite(r,c,nr,nc):
    global mat
    if(mat[nr][nc]==0):#흰색
        idx=stcks[r][c].index(j)
        carrings=stcks[r][c][idx:].copy()#NOTE 시간 초과 위험
        stcks[r][c]=stcks[r][c][:idx]
        stcks[nr][nc].extend(carrings)#정순
    else:#빨강
        idx=stcks[r][c].index(j)
        carrings=stcks[r][c][idx:].copy()#NOTE 시간 초과 위험
        stcks[r][c]=stcks[r][c][:idx]
        stcks[nr][nc].extend(carrings[::-1])#역순
    
    for item in carrings:
        units[item][0],units[item][1]=nr,nc
    
    if(len(stcks[nr][nc])>=4):return 1
    else: return 0

for cnt in range(1,1001):
    for j in range(k):#각각의 말들을 이동(units의 값을 통해 stcks조작)
        r,c,dir=units[j]
        nr,nc=r+dy_dx[dir][0],c+dy_dx[dir][1]
        if(0<=nr<n and 0<=nc<n and mat[nr][nc]!=2):#빨강 또는 흰색
            res=redwhite(r,c,nr,nc)
            if(res):
                print(cnt)
                exit()
        else:#파랑 또는 범위나감
            if(dir==0 or dir==2):
                units[j][2]+=1
            else:
                units[j][2]-=1
            r,c,dir=units[j]
            nr,nc=r+dy_dx[dir][0],c+dy_dx[dir][1]
            if(0<=nr<n and 0<=nc<n and mat[nr][nc]!=2):#빨강 또는 흰색
                res=redwhite(r,c,nr,nc)
                if(res):
                    print(cnt)
                    exit()
print(-1)
#→, ←, ↑, ↓