import sys
a=sys.stdin.readline().rstrip()#각 문자가 열이다.
b=sys.stdin.readline().rstrip()#각 문자가 행이다.
dp_mat=[[0 for _ in range(len(a)+1)] for _ in range(len(b)+1)]
for i in range(1,len(b)+1):
    for j in range(1,len(a)+1):
        dp_mat[i][j]=max(dp_mat[i-1][j],dp_mat[i][j-1],dp_mat[i-1][j-1]+(a[j-1]==b[i-1]))
sys.stdout.write(f'{dp_mat[-1][-1]}')