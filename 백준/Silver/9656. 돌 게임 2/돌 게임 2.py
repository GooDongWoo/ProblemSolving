import sys
input = sys.stdin.readline

n=int(input())
dp=[0]*1001
dp[1]=0
dp[2]=1
dp[3]=0
for i in range(4,1001):
    dp[i]=1 if dp[i-1]==0 or dp[i-3]==0 else 0
if(dp[n]):print("SK")
else:print("CY")
