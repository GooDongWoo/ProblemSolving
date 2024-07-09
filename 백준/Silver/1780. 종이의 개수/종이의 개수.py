import sys
n=int(sys.stdin.readline())
mat=[list(map(int,sys.stdin.readline().split())) for _ in range(n)]
cnt=[0]*3
def divnconq(n,row=0,col=0):
    global mat,cnt
    if(n==1):
        return mat[row][col]

    res=[0]*9
    res[0]=divnconq(n//3,row,col)
    res[1]=divnconq(n//3,row,col+n//3)
    res[2]=divnconq(n//3,row,col+n*2//3)
    
    res[3]=divnconq(n//3,row+n//3,col)
    res[4]=divnconq(n//3,row+n//3,col+n//3)
    res[5]=divnconq(n//3,row+n//3,col+n*2//3)
    
    res[6]=divnconq(n//3,row+n*2//3,col)
    res[7]=divnconq(n//3,row+n*2//3,col+n//3)
    res[8]=divnconq(n//3,row+n*2//3,col+n*2//3)
    
    if(res[0]==res[1]==res[2]==res[3]==res[4]==res[5]==res[6]==res[7]==res[8] and (res[0]==1 or res[0]==0 or res[0]==-1)):
        return res[0]
    else:
        for i in range(9):
            if res[i]!=None:
                cnt[res[i]]+=1
        return None
if(n==1):
    cnt[mat[0][0]]+=1
else:
    tmp=divnconq(n)
    if(tmp!=None):
        cnt[tmp]+=1
for i in range(-1,2):
    print(cnt[i])