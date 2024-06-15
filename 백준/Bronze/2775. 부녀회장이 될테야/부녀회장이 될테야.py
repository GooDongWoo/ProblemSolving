result_mat=[[0 for _ in range(15)] for _ in range(15)]
result_mat[0]=[i for i in range(15)]
for i in range(1,15):
    for j in range(1,15):
        result_mat[i][j]=sum(result_mat[i-1][1:j+1])

n_test=int(input())
for _ in range(n_test):
    k=int(input())
    n=int(input())
    print(result_mat[k][n])