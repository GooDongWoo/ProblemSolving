import sys
input=sys.stdin.readline
n,m=map(int,input().split())
mat=[list(map(int,list(input().rstrip()))) for _ in range(n)]
cnter=0
def F(r,c):
    global mat
    for i in range(r+1):
        for j in range(c+1):
            mat[i][j]^=1

for i in range(n-1,-1,-1):
    for j in range(m-1,-1,-1):
        if(mat[i][j]):
            F(i,j)
            cnter+=1
print(cnter)