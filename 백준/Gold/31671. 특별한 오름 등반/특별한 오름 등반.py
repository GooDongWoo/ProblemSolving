import sys
input=sys.stdin.readline

MAX = 1000
san = [[0] * (2 * MAX + 1) for _ in range(MAX + 1)]

n, m = map(int, input().split())
for _ in range(m):
    bx, by = map(int, input().split())
    r, c = by, bx
    san[r][c] = -1

san[0][0] = 1
for c in range(1, n + 1):
    for r in range(n + 1):
        if san[r][c] == -1: continue
        if r - c > 0 : break
        if r + 1 <= c-1 and san[r+1][c-1] > 0:
            san[r][c] = max(san[r][c], san[r+1][c-1], r)
        if 0 <= r - 1 and san[r-1][c-1] > 0:
            san[r][c] = max(san[r][c], san[r-1][c-1], r)

for c in range(n + 1, 2 * n + 1):
    for r in range(n + 1):
        if san[r][c] == -1: continue
        if r + c > 2 * n : break
        if san[r+1][c-1] > 0:
            san[r][c] = max(san[r][c], san[r+1][c-1], r)
        if r-1>0 and san[r-1][c-1] > 0:
            san[r][c] = max(san[r][c], san[r-1][c-1], r)
if san[0][2*n] == 0:print(-1)
else:print(san[0][2*n])