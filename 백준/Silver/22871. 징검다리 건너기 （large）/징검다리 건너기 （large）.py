import sys
input = sys.stdin.readline

INF = int(1e50)
n = int(input())
l = list(map(int, input().split()))
dp = [INF] * n
dp[0] = 0
for i in range(n - 1):
    for j in range(i + 1, n):
        dp[j] = min(dp[j], max((j - i) * (1 + abs(l[i] - l[j])), dp[i]))

print(dp[-1])