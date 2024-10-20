import sys
input=sys.stdin.readline
n=int(input())
l=list(map(int, input().split()))
dp=[[[0,0] for _ in range(3)] for _ in range(2)] #min, max
for i in range(3):
    for j in range(2):
        dp[0][i][j]=l[i]

for i in range(1,n):
    l=list(map(int, input().split()))
    for j in range(3):
        if (j==0):
            dp[1][j][0]=min(dp[0][j][0], dp[0][j+1][0])+l[j]
            dp[1][j][1]=max(dp[0][j][1], dp[0][j+1][1])+l[j]
        elif(j==1):
            dp[1][j][0]=min(dp[0][j-1][0],dp[0][j][0], dp[0][j+1][0])+l[j]
            dp[1][j][1]=max(dp[0][j-1][1],dp[0][j][1], dp[0][j+1][1])+l[j]
        else:
            dp[1][j][0]=min(dp[0][j-1][0],dp[0][j][0])+l[j]
            dp[1][j][1]=max(dp[0][j-1][1],dp[0][j][1])+l[j]
    dp[0]=dp[1]
    dp[1]=[[0,0] for _ in range(3)]
max1=max(dp[0], key=lambda x:x[1])[1]
min1=min(dp[0], key=lambda x:x[0])[0]
print(max1, min1)