n,m=map(int,input().split())
mat=[list(map(int,input().split())) for _ in range(n)]
s_mat=[[0]*(m+1) for _ in range(n+1)]
for i in range(1,n+1):
    for j in range(1,m+1):
        s_mat[i][j]=s_mat[i-1][j]+s_mat[i][j-1]+mat[i-1][j-1]-s_mat[i-1][j-1]
k=int(input())
for _ in range(k):
    sr,sc,er,ec=map(int,input().split())
    print(s_mat[er][ec]-s_mat[er][sc-1]-s_mat[sr-1][ec]+s_mat[sr-1][sc-1])