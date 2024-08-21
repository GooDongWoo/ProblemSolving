import sys
n=int(sys.stdin.readline())
mat=[list(map(int,sys.stdin.readline().split())) for _ in range(n)]
dy_dx=[(0,0),(1,0),(0,1),(1,1)]
while n//2:
    n=n//2
    nmat=[[0]*n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            tmp=sorted([mat[2*i+dy][2*j+dx] for dy,dx in dy_dx])
            nmat[i][j]=tmp[-2]
    mat=nmat
print(nmat[-1][-1])