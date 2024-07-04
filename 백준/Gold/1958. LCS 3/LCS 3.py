import sys
a=(sys.stdin.readline().rstrip())
b=(sys.stdin.readline().rstrip())
c=(sys.stdin.readline().rstrip())
dp=[[[0]*(len(a)+1) for _ in range(len(b)+1)]for _ in range(len(c)+1)]
for k in range(1,len(c)+1):
    for i in range(1,len(b)+1):
        for j in range(1,len(a)+1):
                dp[k][i][j]=max(dp[k][i-1][j-1],dp[k-1][i][j-1],dp[k-1][i-1][j],dp[k][i][j-1],dp[k][i-1][j],dp[k-1][i][j],dp[k-1][i-1][j-1]+(a[j-1]==b[i-1] and b[i-1]==c[k-1]))
sys.stdout.write(f'{dp[-1][-1][-1]}')