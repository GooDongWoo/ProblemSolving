import sys,heapq
sys.setrecursionlimit(10 ** 7)
input=sys.stdin.readline


m, n = map(int, input().split())
if n == 0:
    print(0)
    sys.exit()
l = [-1] * n
for i in range(m):
    a, b = map(int, input().split())
    l[a] = b

vis = [False] * n
vis2 = [False] * n
dp = [1] * n
for i in range(n):
    if l[i] != -1 and not vis[i]:
        x = i
        g = True
        u = set()
        while not vis[x]:
            vis[x] = True
            u.add(x)
            if l[x] == -1:
                g = False
                break
            x = l[x]
        if g and x in u:
            cycle_p = []
            while not vis2[x]:
                vis2[x] = True
                cycle_p.append(x)
                x = l[x]
            for i in cycle_p:
                dp[i] = len(cycle_p)
for i in range(n):
    if not vis2[i]:
        x = i
        L = []
        while not vis2[x] and l[x] != -1:
            L.append(x)
            vis2[x] = True
            x = l[x]
        vis2[x] = True
        t = dp[x]
        for i in L[::-1]:
            t += 1
            dp[i] = t
print(max(dp))