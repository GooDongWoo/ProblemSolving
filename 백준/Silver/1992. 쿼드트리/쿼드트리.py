import sys
n=int(sys.stdin.readline())
mat=[list(sys.stdin.readline().rstrip()) for _ in range(n)]

def divnconq(n,row=0,col=0):
    global mat,div_pattern
    if(n==1):
        return mat[row][col]
    res=[0]*4
    res[0]=divnconq(n//2,row,col)
    res[1]=divnconq(n//2,row,col+n//2)
    res[2]=divnconq(n//2,row+n//2,col)
    res[3]=divnconq(n//2,row+n//2,col+n//2)
        
    if(res[0]==res[1]==res[2]==res[3] and (res[0]=='1' or res[0]=='0')):
        return res[0]
    else:
        return f'({res[0]}{res[1]}{res[2]}{res[3]})'

print(divnconq(n))