import sys
input=sys.stdin.readline

n, m = map(int, input().split())
mems = list(map(int, input().split()))
costs = list(map(int, input().split()))

MAX = sum(costs)
dp = [0] * (MAX + 1)
dp[0] = 0
for i in range(n):
    for j in range(MAX - costs[i],-1,-1):
        dp[j + costs[i]] = max(dp[j + costs[i]], dp[j] + mems[i])

for cost in range(MAX + 1):
    if (dp[cost] >= m):
        print(cost)
        break