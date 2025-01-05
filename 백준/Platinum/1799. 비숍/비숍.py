import sys
input=sys.stdin.readline

def chck(r, c):
    global n, mat
    #lu
    incre = 1
    while 1:
        nr, nc = r - incre , c - incre
        if 0 <= nr < n and 0 <= nc < n:
            if (mat[nr][nc] == 2): return False
        else: break
        incre += 1
    #ru
    incre = 1
    while 1:
        nr, nc = r - incre , c + incre
        if 0 <= nr < n and 0 <= nc < n:
            if (mat[nr][nc] == 2): return False
        else: break
        incre += 1
    #rd
    incre = 1
    while 1:
        nr, nc = r + incre , c + incre
        if 0 <= nr < n and 0 <= nc < n:
            if (mat[nr][nc] == 2): return False
        else: break
        incre += 1
    #ld
    incre = 1
    while 1:
        nr, nc = r + incre , c - incre
        if 0 <= nr < n and 0 <= nc < n:
            if (mat[nr][nc] == 2): return False
        else: break
        incre += 1
    return True

def bt1(idx):
    global n, mat, l1, res1
    if idx == len(l1):
        res1 = max(res1, sum([1 for y, x in l1 if mat[y][x] == 2]))
    else:
        y, x = l1[idx]
        if chck(y, x):
            mat[y][x] = 2
            bt1(idx+1)
            mat[y][x] = 1
            bt1(idx+1)
        else:bt1(idx+1)

def bt2(idx):
    global n, mat, l1, res2
    if idx == len(l2):
        res2 = max(res2, sum([1 for y, x in l2 if mat[y][x] == 2]))
    else:
        y, x = l2[idx]
        if chck(y, x):
            mat[y][x] = 2
            bt2(idx+1)
            mat[y][x] = 1
            bt2(idx+1)
        else:bt2(idx+1)    

n = int(input())
mat = [list(map(int, input().split())) for _ in range(n)]# 0: 위치불가, 1: 위치 가능, 2: 이미 배치

l1 = [];l2 = []
for i in range(n):
    for j in range(n):
        if mat[i][j] == 0: continue
        if (i + j) % 2 == 0:l1.append((i, j))
        else:l2.append((i, j))
res1 = 0
res2 = 0
bt1(0)
bt2(0)
print(res1 + res2)