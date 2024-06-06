import sys

n,k=map(int,sys.stdin.readline().split())
combination_mat=[[0 for _ in range(n+1)] for _ in range(n+1)]
for i in range(1,n+1):
    combination_mat[i][0]=1
    combination_mat[i][i]=1


for i in range(1,n+1):
    for j in range(1,i):
        combination_mat[i][j]=combination_mat[i-1][j-1]+combination_mat[i-1][j]

print(combination_mat[n][k]%10007)