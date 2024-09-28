import sys
input=sys.stdin.readline
dys=[-1,-1,0,1,1,1,0,-1]
dxs=[0,-1,-1,-1,0,1,1,1]
mat=[[] for _ in range(4)]
for i in range(4):
    tmp=[*map(int,input().split())]
    for j in range(0,8,2):
        mat[i].append((tmp[j],tmp[j+1]-1))

fl=[0]*16
for i in range(4):
    for j in range(4):
        fl[mat[i][j][0]-1]=(i,j)

score=[]
#shark input
sy,sx=0,0
score.append(mat[0][0][0])
fl[mat[0][0][0]-1]=0
mat[0][0]=(-1,mat[0][0][1])

def moveChck(y,x,sy,sx,drc):
    global dys,dxs
    ny,nx=y+dys[drc],x+dxs[drc]
    if(0<=ny<4 and 0<=nx<4 and not (ny==sy and nx==sx)):
        return True
    else:
        return False

#def fish move
def fishMove(pan,sy,sx,fl):
    for i in range(len(fl)):
        if(fl[i]):
            y,x=fl[i]
            drc=pan[y][x][1]
            while not moveChck(y,x,sy,sx,drc):#가려는 곳이 안되면 계속 바꾸기
                drc=(drc+1)%8
                pan[y][x]=(pan[y][x][0],drc)
            #스왑하기, 데이터 반영하기 pan, fl
            ny,nx=y+dys[drc],x+dxs[drc]
            if pan[ny][nx]:
                s1=pan[ny][nx][0]-1
                fl[i],fl[s1]=fl[s1],fl[i]
                pan[ny][nx], pan[y][x]=pan[y][x],pan[ny][nx]
            else:
                fl[i]=(ny,nx)
                pan[ny][nx], pan[y][x]=pan[y][x],pan[ny][nx]

    return pan,fl

#def shark move iteratively
def sharkMove(pan,sy,sx,fl,incre):
    global dys,dxs,score
    drc=pan[sy][sx][1]
    ny,nx=sy+dys[drc]*incre,sx+dxs[drc]*incre

    plus=pan[ny][nx][0]
    score.append(plus)
    pan[sy][sx]=0
    pan[ny][nx]=(-1,pan[ny][nx][1])
    fl[plus-1]=0
    sy,sx=ny,nx
    return pan,sy,sx,fl

def makeCases(pan,sy,sx):
    global dys,dxs,score
    drc=pan[sy][sx][1]
    dy,dx=dys[drc],dxs[drc]
    incre=1
    cases=[]
    while 1:
        ny,nx=sy+dy*incre,sx+dx*incre
        if(0<=ny<4 and 0<=nx<4):
            if(pan[ny][nx]):
                cases.append(incre)
            incre+=1
        else:break
    return cases
sl=[]
def bt(pan,sy,sx,fl):
    global score,cnt
    pan,fl=fishMove(pan,sy,sx,fl)

    cases=makeCases(pan,sy,sx)
    if not (cases):
        sl.append(sum(score))
        return

    for incre in cases:
        npan=[i.copy() for i in pan]
        nfl=fl.copy()
        npan,nsy,nsx,nfl=sharkMove(npan,sy,sx,nfl,incre)
        bt(npan,nsy,nsx,nfl)
        score.pop()
        #redo

bt(mat,sy,sx,fl)
print(max(sl))