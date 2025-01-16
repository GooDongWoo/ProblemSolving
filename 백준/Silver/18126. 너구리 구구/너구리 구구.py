import sys
input = sys.stdin.readline

INF = int(1e10)
n = int(input())
adj_mat = [[INF]*n for _ in range(n)]
for _ in range(n-1):
    a, b, c = map(int, input().split())
    adj_mat[a-1][b-1] = c
    adj_mat[b-1][a-1] = c

v = [0]*n
dist = [INF]*n

stck = [(0, 0)]
while stck:
    curd, p = stck.pop()
    if v[p]: continue
    v[p] = 1
    dist[p] = curd
    
    for i in range(n):
        if adj_mat[p][i] != INF and v[i] == 0:
            stck.append((curd+adj_mat[p][i], i))

print(max(dist))