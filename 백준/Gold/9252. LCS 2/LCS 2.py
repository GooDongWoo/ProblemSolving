import sys
a=list(sys.stdin.readline().rstrip())
b=list(sys.stdin.readline().rstrip())
dp_mat=[['' for _ in range(len(a)+1)] for _ in range(len(b)+1)]
for i in range(1,len(b)+1):
    for j in range(1,len(a)+1):
        if(a[j-1]==b[i-1]):
            tmp=max(len(dp_mat[i-1][j-1]+a[j-1]), len(dp_mat[i][j-1]), len(dp_mat[i-1][j]))
            if tmp==len(dp_mat[i-1][j-1]+a[j-1]):
                dp_mat[i][j]=dp_mat[i-1][j-1]+a[j-1]
                
            elif tmp==len(dp_mat[i][j-1]):
                dp_mat[i][j]=dp_mat[i][j-1]
            else:
                dp_mat[i][j]=dp_mat[i-1][j]
        else:
            tmp=max(len(dp_mat[i][j-1]), len(dp_mat[i-1][j]))
            if tmp==len(dp_mat[i][j-1]):
                dp_mat[i][j]=dp_mat[i][j-1]
            else:
                dp_mat[i][j]=dp_mat[i-1][j]            

i=len(b)
j=len(a)
sys.stdout.write(f'{len(dp_mat[i][j])}\n{dp_mat[i][j]}')