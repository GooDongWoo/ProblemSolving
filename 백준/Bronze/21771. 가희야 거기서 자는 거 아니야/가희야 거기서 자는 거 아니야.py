r, c = map(int, input().split())
r1, c1, r2, c2 = map(int, input().split())
mat = [list(input().rstrip()) for _ in range(r)]
cnter = 0
for i in range(r):
    for j in range(c):
        if(mat[i][j] == 'P'):
            cnter += 1
if(cnter == r2*c2):
    print(0)
else:
    print(1)