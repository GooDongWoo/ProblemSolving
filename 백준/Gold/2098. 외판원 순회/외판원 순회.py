N = int(input())
cost = [list(map(int,input().split())) for _ in range(N)]

def find(visited,now):
    if dp[visited][now]: return dp[visited][now]
    if visited == (1<<N) - 1:
        return cost[now][0] if cost[now][0] > 0 else 10**9
    
    tmp = 10**8
    for i in range(1,N):
        if (not (visited >> i) % 2) and cost[now][i]:
            tmp = min(tmp, find(visited | (1<<i), i) + cost[now][i])

    dp[visited][now] = tmp
    return tmp
dp = [[0]*N for _ in range(1<<N)]

print(find(1,0))