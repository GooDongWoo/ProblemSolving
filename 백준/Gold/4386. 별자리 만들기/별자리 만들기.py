import sys
input = sys.stdin.readline

import heapq

n = int(input())
stars = sorted([(tuple(map(float, input().split()))) for _ in range(n)])

adj_mat = [[0]*n for _ in range(n)]
for i in range(n):
    for j in range(n):
        if i == j: continue
        adj_mat[j][i] = adj_mat[i][j] = (stars[i][0] - stars[j][0])**2 + (stars[i][1] - stars[j][1])**2

v = [0]*n
h = []

v[0] = 1
for i in range(1, n):
    heapq.heappush(h, (adj_mat[0][i], i))

cnter = 0
while h:
    cdist, cur = heapq.heappop(h)
    if v[cur]: continue
    v[cur] = 1
    cnter += cdist **.5
    
    
    for i in range(n):
        if v[i]: continue
        heapq.heappush(h, (adj_mat[cur][i], i))

print(cnter)