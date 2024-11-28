import sys
from collections import deque
input=sys.stdin.readline

n = int(input())
m = int(input())
mat = [list(map(int, input().split())) for _ in range(n)]
jump = int(input())
tmp = []
dy_dx = []
for i in range(1, jump + 1):
    for j in range(jump -i + 1):
        dy_dx.append((i,j))

tmp = dy_dx[:]
for y, x in tmp:
    dy_dx.append((-y, -x))
    dy_dx.append((x, -y))
    dy_dx.append((-x, y))

def dfs(sy, sx):
    global n, m, mat, dy_dx
    
    v = [[0]*m for _ in range(n)]
    stck = deque()
    stck.append((sy,sx))
    start_c = mat[sy][sx]
    while stck:
        cy, cx = stck.pop()
        if v[cy][cx] == 1: continue
        if (cy == n - 1) and (cx == m - 1): print('ALIVE'); return
        v[cy][cx] = 1
        
        for dy, dx in dy_dx:
            ny, nx = cy + dy, cx + dx
            if (0<= ny < n and 0<= nx < m and v[ny][nx] == 0 and mat[ny][nx] == start_c):
                stck.append((ny, nx))
    print('DEAD'); return 
dfs(0,0)