import sys
input = sys.stdin.readline

r, c, q = map(int, input().split())
mat = [list(map(int, input().split())) for _ in range(r)]
qs = [list(map(int, input().split())) for _ in range(q)]

pref_sum = [[0] * (c + 1) for _ in range(r + 1)]
for i in range(r):
    pref_sum[i + 1][0 + 1] = pref_sum[i][0 + 1] + mat[i][0]

for i in range(c):
    pref_sum[0 + 1][i + 1] = pref_sum[0 + 1][i] + mat[0][i]

for i in range(1, r):
    for j in range(1, c):
        pref_sum[i + 1][j + 1] = pref_sum[i][j + 1] + pref_sum[i + 1][j] - pref_sum[i][j] + mat[i][j]

def F(r1, c1, r2, c2):
    global pref_sum
    return (pref_sum[r2][c2] - pref_sum[r1 - 1][c2] - pref_sum[r2][c1 - 1] + pref_sum[r1 - 1][c1 - 1]) // ((r2 - r1 + 1) * (c2 - c1 + 1))

for i in range(q):
    sys.stdout.write(f'{(F(*qs[i]))}\n')