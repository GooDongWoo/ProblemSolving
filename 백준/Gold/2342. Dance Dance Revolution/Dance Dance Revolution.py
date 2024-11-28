import sys
input=sys.stdin.readline

INF = int(1e9)
cases = [(0,1),(0,2),(0,3),(0,4),(1,2),(1,3),(1,4),(2,3),(2,4),(3,4)]
c2i = dict()
i2c = dict()
for idx, item in enumerate(cases):
    c2i[item] = idx
    i2c[idx] = item

qs = list(map(int, input().split()))
qs.pop()

dp = [[INF] * 10 for _ in range(len(qs))]
if qs[0] == 0: print(0);exit()

dp[0][c2i[(0, qs[0])]] = 2
for i in range(1, len(qs)):
    cur = qs[i]
    for idx, j in enumerate(dp[i - 1]):
        if j < INF:
            n1, n2 = i2c[idx] # n1 < n2
            if ((n1 == cur) or (n2 == cur)):
                dp[i][idx] = min(dp[i][idx], dp[i-1][idx] + 1)
            else:
                #n1 -> cur
                nidx = c2i[(min(cur, n2), max(cur, n2))]
                if n1 == 0:plus1 = 2
                elif abs(cur - n1) == 2: plus1 = 4
                else: plus1 = 3
                dp[i][nidx] = min(dp[i][nidx], dp[i-1][idx] + plus1)

                #n2 -> cur
                nidx = c2i[(min(cur, n1), max(cur, n1))]
                if abs(cur - n2) == 2: plus1 = 4
                else: plus1 = 3
                dp[i][nidx] = min(dp[i][nidx], dp[i-1][idx] + plus1)

print(min(dp[-1]))