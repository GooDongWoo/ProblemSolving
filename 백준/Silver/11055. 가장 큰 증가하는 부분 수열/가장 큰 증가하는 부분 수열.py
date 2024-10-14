import sys
input=sys.stdin.readline
n=int(input())
l=[*map(int,input().split())]
dp=[0]*n
dp[0]=l[0]
for i in range(1,n):
    dp[i]=l[i]
    for j in range(i):
        if(l[i]>l[j]):
            dp[i]=max(dp[j]+l[i],dp[i])
print(max(dp))