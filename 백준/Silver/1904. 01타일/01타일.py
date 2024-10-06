n=int(input())
if(n==1):
    print(1)
    exit()
dp=[[0]*2 for _  in range(n+1)]
dp[1][0]=0
dp[1][1]=1
dp[2][0]=1
dp[2][1]=dp[1][0]+dp[1][1]
for i in range(3,n+1):
    dp[i][0]=sum(dp[i-2])%15746
    dp[i][1]=sum(dp[i-1])%15746

print(sum(dp[-1])%15746)