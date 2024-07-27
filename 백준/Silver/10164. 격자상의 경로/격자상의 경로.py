n,m,k=map(int,input().split())

comb=[[0]*31 for _ in range(31)]
for i in range(1,31):
    comb[i][0]=1
    comb[i][i]=1
for i in range(2,31):
    for j in range(1,i):
        comb[i][j]=comb[i-1][j-1]+comb[i-1][j]

if(k==0):
    print(comb[n+m-2][n-1])
else:
    row=(k-1)//m
    col=(k-1)%m
    print(comb[row+col][col]*comb[n-1-row+m-1-col][n-row-1])