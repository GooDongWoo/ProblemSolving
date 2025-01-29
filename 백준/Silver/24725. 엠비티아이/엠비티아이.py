import sys
input = sys.stdin.readline

mbtis = dict()
for i in ['I','E']:
    for j in ['N','S']:
        for k in ['T','F']:
            for l in ['P','J']:
                mbtis[i+j+k+l] = 1
n, m = map(int, input().split())
mat = list(input().rstrip() for _ in range(n))
dy_dx = [(1,0),(1,1),(0,1),(-1,1),(-1,0),(-1,-1),(0,-1),(1,-1)]
cnter = 0
for i in range(n):
    for j in range(m):
        for dy, dx in dy_dx:
            ly, lx = i + (3 * dy),j + (3 * dx)
            if (not(0<=ly<n and 0<=lx<m)):continue
            nw = ""
            for k in range(4): nw += mat[i + k*dy][j + k*dx]
            if (nw in mbtis): cnter += 1
print(cnter)