import sys
input=sys.stdin.readline
n=int(input())
ps=[0]*n
for i in range(n):
    ps[i]=tuple(map(lambda x: int(x)+15,input().split()))
r=15*2 + 1
dx_dy=[(0,1),(1,0),(0,-1),(-1,0)]
ol=['W','D','X','A']
sy=sx=0
o_log=[]
didx=0
idx_mat=[[0]*r for _ in range(r)]
v=[[0]*r for _ in range(r)]
v[0][0]=1
idx=1
while 1:
    if(sy==15 and sx==15):break
    ny,nx=sy+dx_dy[didx][0],sx+dx_dy[didx][1]
    if(0<=ny<r and 0<=nx<r and v[ny][nx]==0):
        sy,sx=ny,nx
    else:
        didx=(didx+1)%4
        ny,nx=sy+dx_dy[didx][0],sx+dx_dy[didx][1]
        sy,sx=ny,nx
    v[sy][sx]=1
    idx_mat[sy][sx]=idx
    o_log.append(ol[didx])
    idx+=1

for i in range(n):
    x,y=ps[i]
    print(''.join(o_log[idx_mat[x][y]:]))