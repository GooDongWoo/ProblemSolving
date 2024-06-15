result_mat=[1000001]*1000001
result_mat[0]=0
result_mat[1]=0
result_mat[2]=1
result_mat[3]=1
for i in range(4,1000001):
    tmp1=1000001
    tmp2=1000001
    if(i%3==0):
        tmp1=min(result_mat[i//3]+1,result_mat[i-1]+1)
    if(i%2==0):
        tmp2=min(result_mat[i//2]+1,result_mat[i-1]+1)
    result_mat[i]=min(tmp1,tmp2,result_mat[i-1]+1)

n=int(input())
print(result_mat[n])