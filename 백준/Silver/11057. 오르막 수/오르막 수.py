import sys
input = sys.stdin.readline
n=int(input())
dp=[[0]*10 for _ in range(n+1)]
for i in range(10):
    dp[1][i]=1
for i in range(2,n+1):
    for j in range(1,10):
        dp[i][j]=sum(dp[i-1][j:])
print(sum([sum(ll)%10007 for ll in dp])%10007)