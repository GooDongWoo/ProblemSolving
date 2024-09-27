import sys
input=sys.stdin.readline
n=int(input())
a=[*map(int,input().split())]
dp=[[0]*2 for _ in range(n+2)]

#last standard
na=a[:]+[0,0]
dp[0][0]=na[0]
dp[0][1]=na[0]

dp[1][0]=dp[0][0]+na[1]
dp[1][1]=dp[0][0]+na[1]

dp[2][0]=dp[1][0]+na[2]
dp[2][1]=0+2*sum(na[0:0+3])

for i in range(3,n+2):
    dp[i][0]=max(dp[i-1])+na[i]
    dp[i][1]=max(dp[i-3])+2*sum(na[i-2:i+1])

print(max(dp[-1]))
#first standard