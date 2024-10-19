import sys
import math
input = sys.stdin.readline
n=int(input())
INF=int(1e9)
dp=[INF]*10001
dp[1]=1
dp[2]=2
for i in range(3,n+1):
    for j in range(1,(i//2)+1):
        dp[i]=min(dp[i],dp[j]+dp[i-j])
    for j in range(2,int(math.sqrt(i))+1):
        if(i%j==0):
            a,b=i//j,j
            dp[i]=min(dp[i],dp[a]+dp[b])
    if(i<8):
        dp[math.factorial(i)]=dp[i]

print(dp[n])