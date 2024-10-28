import sys
input=sys.stdin.readline
n=int(input())
l=list(map(int,input().split()))
dp=[[1]*2 for _ in range(n)]
for i in range(1,n):
    for j in range(i):
        if l[j]<l[i]:
            dp[i][0]=max(dp[i][0],dp[j][0]+1)
        elif l[j]>l[i]:
            dp[i][1]=max(dp[i][1],dp[j][0]+1,dp[j][1]+1)

print(max([max(i) for i in dp]))