import sys
input=sys.stdin.readline
r,c=8,7
mat=[list(map(int,list(input().rstrip()))) for _ in range(r)]
v=[[0]*c for _ in range(r)]
dominos=[]
d_v=[0]*28
for i in range(7):
    for j in range(i,7):dominos.append((i,j))
batch=[[(0,0),(0,1)],[(0,1),(0,0)],[(0,0),(1,0)],[(1,0),(0,0)]]
cnt=0

def bt(i,j):
    global r,c,mat,v,dominos,d_v,batch,cnt
    if(i==8 and j==0):cnt+=1
    elif(j>=7):bt(i+1,0)
    elif(v[i][j]):bt(i,j+1)
    else:
        for didx in range(28):
            if(d_v[didx]):continue
            d_v[didx]=1
            v1,v2=dominos[didx]
            range1=[0,1,2,3] if v1!=v2 else [0,2]
            for ridx in range1:
                ny1,nx1,ny2,nx2=i+batch[ridx][0][0],j+batch[ridx][0][1],i+batch[ridx][1][0],j+batch[ridx][1][1]
                if(0<=ny1<r and 0<=nx1<c and 0<=ny2<r and 0<=nx2<c and v[ny1][nx1]==0 and v[ny2][nx2]==0 and mat[ny1][nx1]==v1 and mat[ny2][nx2]==v2):
                    v[ny1][nx1]=1; v[ny2][nx2]=1
                    bt(i,j+1)
                    v[ny1][nx1]=0; v[ny2][nx2]=0
            d_v[didx]=0
bt(0,0)
print(cnt)