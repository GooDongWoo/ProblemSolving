import sys
input = sys.stdin.readline

def dist(a, b):
    return (a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2

n = int(input())
mat = [list(map(int, input().split())) for _ in range(n)]

for i in range(n):
    for j in range(n):
        if mat[i][j] == 5:
            p = (i, j)
        elif mat[i][j] == 2:
            t = (i, j)

miny, maxy = min(p[0], t[0]), max(p[0], t[0])
minx, maxx = min(p[1], t[1]), max(p[1], t[1])
cnter = 0
for i in range(miny, maxy + 1):
    for j in range(minx, maxx + 1):
        if mat[i][j] == 1:
            cnter += 1
if dist(p, t) >= 25 and cnter >= 3:
    print(1)
else:
    print(0)