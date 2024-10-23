import sys
input = sys.stdin.readline
n=int(input())
dp=[0]*10001
dp[1]=1
for i in range(2,10001):
    cnt=0
    for j in range(1,int(i**(.5))+1):
        if(i%j==0):
            cnt+=1
    dp[i]=dp[i-1]+cnt
print(dp[n])