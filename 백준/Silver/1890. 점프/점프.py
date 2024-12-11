import sys
input = sys.stdin.readline

dy_dx = [(1,0),(0,1)]
n = int(input())
mat = [list(map(int, input().split())) for _ in range(n)]
dp = [[0] * n for _ in range(n)]
dp[0][0] = 1
for i in range(n):
    for j in range(n):
        if dp[i][j] == 0: continue
        if i == n - 1 and j == n - 1: continue
        if mat[i][j] + j < n:
            dp[i][mat[i][j] + j] += dp[i][j]
        if mat[i][j] + i < n:
            dp[mat[i][j] + i][j] += dp[i][j]

print(dp[-1][-1])