import sys
input = sys.stdin.readline

n = int(input())
dp = [[[0]*1024 for _ in range(10)] for _ in range(100)]

for i in range(1,10):
    dp[0][i][(1 << i)] = 1

for i in range(1,100):
    for j in range(10):
        for k in range(1,1024):
            if ((1 << j) & (k)):
                if (j == 0):
                    dp[i][j][k] = dp[i-1][1][k] + dp[i-1][1][k & (~(1<<j))]
                elif(j == 9):
                    dp[i][j][k] = dp[i-1][8][k] + dp[i-1][8][k & (~(1<<j))]
                else:
                    dp[i][j][k] = dp[i-1][j-1][k] + dp[i-1][j-1][k & (~(1<<j))] + dp[i-1][j+1][k] + dp[i-1][j+1][k & (~(1<<j))]

ans = 0
for i in range(10):
    ans += dp[n-1][i][1023]
print(ans%(int(1e9)))