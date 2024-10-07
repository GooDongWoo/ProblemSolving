import sys
input=sys.stdin.readline
n=int(input())
ps=[*map(int,input().split())]
dp=[[0]*(n+1) for _ in range(n)]

for i in range(1,n+1):
    dp[0][i]=ps[0]*i
    
for i in range(1,n):
    for j in range(1,n+1):
        if(j-(i+1)<0):
            tmp=dp[i-1][j]
        elif j-(i+1)==0:
            tmp=ps[i]
        else:
            tmp=dp[i][j-(i+1)]+ps[i]
        dp[i][j]=max(dp[i-1][j],tmp)
print(dp[-1][-1])