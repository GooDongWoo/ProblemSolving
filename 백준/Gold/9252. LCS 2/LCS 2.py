import sys
a=list(sys.stdin.readline().rstrip())
b=list(sys.stdin.readline().rstrip())
dp_mat=[[0 for _ in range(len(a)+1)] for _ in range(len(b)+1)]
for i in range(1,len(b)+1):
    for j in range(1,len(a)+1):
        tmp=(b[i-1]==a[j-1])
        dp_mat[i][j]=max(dp_mat[i-1][j-1]+tmp, dp_mat[i][j-1], dp_mat[i-1][j])
i=len(b)
j=len(a)
sys.stdout.write(f'{dp_mat[i][j]}\n')
if(dp_mat[i][j]):
    res=[]
    while i>=1 and j>=1:
        if((b[i-1]==a[j-1])):res.append(b[i-1]);i-=1;j-=1
        elif(dp_mat[i][j]==dp_mat[i][j-1]):j-=1
        else:i-=1
    sys.stdout.write(f'{"".join(res[::-1])}\n')