import sys
input=sys.stdin.readline
n=int(input())
ps=[0]*n
for i in range(n):
    x,y=map(lambda x: int(x)+15,input().split())
    ps[i]=(max(abs(15-x),abs(15-y)),i,x,y)
r=15*2 + 1
dx_dy=[(-1,0),(-1,1),(0,1),(1,1),(1,0),(1,-1),(0,-1),(-1,-1)]
ol=['A','Q','W','E','D','C','X','Z']

results=[[] for _ in range(n)] 
flags=[0]*n
while sum(flags)!=n:
    ps.sort()
    v=[[0]*r for _ in range(r)]
    for j in range(n):
        val,idx,x,y=ps[j]
        if(flags[idx]):continue
        op_cand=[]
        for i in range(len(ol)):
            dx,dy=dx_dy[i]
            nx,ny=x+dx,y+dy
            if(0<=nx<r and 0<=ny<r and v[nx][ny]==0 and max(abs(15-nx),abs(15-ny)) < val):
                op_cand.append((max(abs(15-nx),abs(15-ny)),idx,nx,ny,i))
        if(op_cand): # down
            val,idx,nx,ny,oidx=op_cand[0]
            ps[j]=(val,idx,nx,ny)
            v[nx][ny]=1
            results[idx].append(ol[oidx])
            if(nx==15 and ny==15):flags[idx]=1
        else: # ccw rotate
            c1=(abs(x-15)==val)
            c2=(abs(y-15)==val)
            if(c1 and c2):#
                if(x-15<0 and y-15<0):#
                    nx,ny,oidx=x+1,y,dx_dy.index((1,0))
                elif(x-15<0 and y-15>0):#
                    nx,ny,oidx=x,y-1,dx_dy.index((0,-1))
                elif(x-15>0 and y-15>0):#
                    nx,ny,oidx=x-1,y,dx_dy.index((-1,0))
                else:#
                    nx,ny,oidx=x,y+1,dx_dy.index((0,1))
            elif(c1):
                if(x-15<0):nx,ny,oidx=x,y-1,dx_dy.index((0,-1))
                else:nx,ny,oidx=x,y+1,dx_dy.index((0,1))
            else:
                if(y-15<0):nx,ny,oidx=x+1,y,dx_dy.index((1,0))
                else:nx,ny,oidx=x-1,y,dx_dy.index((-1,0))
            ps[j]=(val,idx,nx,ny)
            v[nx][ny]=1
            results[idx].append(ol[oidx])
for i in range(n):
    print(*results[i],sep='')