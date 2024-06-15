import sys
n=int(input())
stair_list=[0]*(n+1)
for i in range(1,n+1):
    stair_list[i]=int(sys.stdin.readline())

result_mat=[[0 for _ in range(2)] for _ in range(n+1)]
result_mat[1][0]=result_mat[0][0]+stair_list[1]
if(n>1):
    result_mat[2][0]=result_mat[1][0]+stair_list[2]
    result_mat[2][1]=result_mat[0][1]+stair_list[2]
    for i in range(3,n+1):
        result_mat[i][0]=result_mat[i-1][1]+stair_list[i]
        result_mat[i][1]=max(result_mat[i-2][1]+stair_list[i],result_mat[i-2][0]+stair_list[i])

print(max(result_mat[n][1],result_mat[n][0]))