import sys
n,m=map(int,sys.stdin.readline().split())
stat_mat=[[0 for _ in range(n+1)] for _ in range(n+1)]
for i in range(1,n+1):
    tmp=list(map(int,sys.stdin.readline().split()))
    for j in range(1,n+1):
        stat_mat[i][j]=tmp[j-1]
sum_mat=[[0 for _ in range(n+1)] for _ in range(n+1)]
sum_mat[1][1]=stat_mat[1][1]
for i in range(2,n+1):
    sum_mat[i][1]=sum_mat[i-1][1]+stat_mat[i][1]
    sum_mat[1][i]=sum_mat[1][i-1]+stat_mat[1][i]
for i in range(2,n+1):
    for j in range(2,n+1):
        sum_mat[i][j]=sum_mat[i-1][j]+sum_mat[i][j-1]-sum_mat[i-1][j-1]+stat_mat[i][j]
for _ in range(m):
    #iterative find result
    x1,y1,x2,y2=map(int,sys.stdin.readline().split())
    sys.stdout.write(f'{sum_mat[x2][y2]-sum_mat[x2][y1-1]-sum_mat[x1-1][y2]+sum_mat[x1-1][y1-1]}\n')