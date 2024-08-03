from collections import deque
n,m=map(int,input().split())
mat=[list(input().rstrip()) for _ in range(n)]
for i in range(n):
    for j in range(m):
        if(mat[i][j]=='R'):
            ry,rx=i,j
            mat[i][j]='.'
        elif(mat[i][j]=='B'):
            by,bx=i,j
            mat[i][j]='.'

#기울이는 거 함수 하나 만들기.. 비교할때 
#왼쪽으로 기울일 때는 더 왼쪽에 있는 거를 먼저 움직이고 그 다음거를 움직이며 같은 행렬에 있으면 부딫히게도 구현해야함
def tiltleft(ry,rx,by,bx,mat):#
    goal_flag=0
    if(rx<bx): #r부터 움직인다.
        while mat[ry][rx-1]!='#':
            if(mat[ry][rx-1]=='O'):
                goal_flag=1
                rx-=1
                break
            rx-=1
        if not (goal_flag):
            mat[ry][rx]='#'
        while mat[by][bx-1]!='#':
            if(mat[by][bx-1]=='O'):
                if not (goal_flag):
                    mat[ry][rx]='.'
                return (0,ry,rx,by,bx)
            bx-=1
        if not (goal_flag):
            mat[ry][rx]='.'
        if goal_flag==1:
            return (1,ry,rx,by,bx)
        else:
            return (2,ry,rx,by,bx)
    else:   #b부터 움직인다.
        while mat[by][bx-1]!='#':
            if(mat[by][bx-1]=='O'):
                return (0,ry,rx,by,bx)
            bx-=1
        mat[by][bx]='#'
        while mat[ry][rx-1]!='#':
            if(mat[ry][rx-1]=='O'):
                goal_flag=1
                break
            rx-=1
        mat[by][bx]='.'
        if goal_flag==1:
            return (1,ry,rx,by,bx)
        else:
            return (2,ry,rx,by,bx)
    
def tiltright(ry,rx,by,bx,mat):
    global n,m
    rx=m-1 -rx
    bx=m-1 -bx
    nmat=[v[::-1] for v in mat]
    flag,ry,rx,by,bx=tiltleft(ry,rx,by,bx,nmat)
    rx=m-1 -rx
    bx=m-1 -bx
    return (flag,ry,rx,by,bx)

def tiltup(ry,rx,by,bx,mat):
    global n,m
    nmat=[list(v) for v in zip(*mat)]
    ry,rx=rx,ry
    by,bx=bx,by
    flag,ry,rx,by,bx=tiltleft(ry,rx,by,bx,nmat)
    ry,rx=rx,ry
    by,bx=bx,by
    return (flag,ry,rx,by,bx)

def tiltdown(ry,rx,by,bx,mat):
    global n,m
    nmat=[list(v) for v in zip(*mat)]
    nmat=[v[::-1] for v in nmat]
    ry,rx=rx,ry
    by,bx=bx,by
    rx=n-1 -rx
    bx=n-1 -bx
    flag,ry,rx,by,bx=tiltleft(ry,rx,by,bx,nmat)
    rx=n-1 -rx
    bx=n-1 -bx
    ry,rx=rx,ry
    by,bx=bx,by
    return (flag,ry,rx,by,bx)
        
def bfs(ry,rx,by,bx):
    global mat
    q=deque()
    q.append((ry,rx,by,bx))
    cnt=0
    goal=1
    while q and goal:
        cnt+=1
        if(cnt>10):
            break
        for _ in range(len(q)):
            ry,rx,by,bx=q.popleft()
            for cmd in [tiltleft,tiltright,tiltup,tiltdown]:
                flag,n_ry,n_rx,n_by,n_bx=cmd(ry,rx,by,bx,mat)
                if(flag==2 and not (n_ry==ry and n_rx==rx and n_by==by and n_bx==bx)):
                    q.append((n_ry,n_rx,n_by,n_bx))
                elif(flag==1):
                    goal=0
                    break
    if(goal or cnt>10):
        print(-1)
    else:
        print(cnt)

bfs(ry,rx,by,bx)