import sys
n,m=map(int,sys.stdin.readline().split())
r,c,d=map(int,sys.stdin.readline().split())
dr,dc=[-1,0,1,0],[0,1,0,-1]
mat=[list(map(int,sys.stdin.readline().split())) for _ in range(n)]
visited=[[0]*m for _ in range(n)]
cnt=0
g_flag=0
def move(r,c,d):
    global n,m,dr,dc,mat,cnt
    if(visited[r][c]==0):
        cnt+=1
    visited[r][c]=1
    flag=1
    for i in range(1,5):#i만큼 반시계만큼 회전이니 빼고 
        nr,nc=r+dr[(4+d-i)%4],c+dc[(4+d-i)%4]
        if(0<=nr<n and 0<=nc<m and mat[nr][nc]==0 and visited[nr][nc]==0):
            flag=0 # 1번이라도 움직일 수 있으면 flag 취소하고 그쪽으로 이동 
            move(nr,nc,(4+d-i)%4)
    if(flag):
        nr,nc=r-dr[d],c-dc[d]
        if(0<=nr<n and 0<=nc<m and mat[nr][nc]):#뒤가 벽이면 작동 멈춤
            print(cnt)
            exit()
        else:#뒤로 이동 가능
            move(nr,nc,d)
move(r,c,d)