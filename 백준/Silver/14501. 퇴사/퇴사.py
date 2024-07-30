import sys
n=int(input())
items=[0]*(n)
for i in range(n):
    items[i]=tuple(map(int,sys.stdin.readline().split()))
dp=[0]*(n+1)
for i in range(n+1):
    if(i>0):
        dp[i]=max(dp[i-1],dp[i])
    if(i!=n and i+items[i][0]<=n):
        dp[i+items[i][0]]=max(dp[i+items[i][0]],dp[i]+items[i][1])

print(dp[-1])