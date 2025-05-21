import sys
input=sys.stdin.readline
n=int(input())
mat=[list(map(int,input().split())) for _ in range(n)]
s=[[[0]*3 for _ in range(n)] for _ in range(n)]
s[0][1][0]=1

for j in range(2,n):
    if(mat[0][j]):continue
    s[0][j][0]=s[0][j-1][0]#가

for i in range(1,n):
    for j in range(2,n):
        if(mat[i][j]):continue
        s[i][j][0]=s[i][j-1][0]+s[i][j-1][2]#가
        s[i][j][1]=s[i-1][j][1]+s[i-1][j][2]#세
        s[i][j][2]=s[i-1][j-1][0]+s[i-1][j-1][1]+s[i-1][j-1][2] if mat[i-1][j]==0 and mat[i][j-1]==0 else 0

print(sum(s[-1][-1]))