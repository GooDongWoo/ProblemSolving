import sys
input=sys.stdin.readline
n=int(input())
INF=int(1e8)
dp=[INF]*100001
dp[0]=0
for i in range(1,int(100001**(.5))+1):
    dp[i**2]=1
for i in range(2,100001):
    for j in range(1,int(i**(0.5))+1):
        dp[i]=min(dp[i],dp[j**2]+dp[i-(j**2)])
print(dp[n])