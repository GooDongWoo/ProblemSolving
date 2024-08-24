import sys
n=int(sys.stdin.readline())
m=int(sys.stdin.readline())
dp=[[0]*31 for _ in range(31)]
for i in range(1,31):
    dp[i][0]=1
    dp[i][i]=1

for i in range(2,31):
    for j in range(1,i):
        dp[i][j]=dp[i-1][j-1]+dp[i-1][j]

# n H m-n
# m-1 C m-n
print(dp[m-1][m-n])