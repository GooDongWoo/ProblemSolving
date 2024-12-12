import sys
input = sys.stdin.readline

INF = int(1e9)
n, a, b = map(int, input().split())
a, b = min(a, b), max(a, b)
dp = [INF] * (n + 1)

dp[0] = 0
for i in range(n + 1):
    if i + 1 < n + 1:
        dp[i + 1] = min(dp[i + 1], dp[i] + 1)
    if i + a + 1 < n + 1:
        dp[i + a + 1] = min(dp[i + a + 1], dp[i] + 1)
    if i + b + 1 < n + 1:
        dp[i + b + 1] = min(dp[i + b + 1], dp[i] + 1)

print(dp[-1])