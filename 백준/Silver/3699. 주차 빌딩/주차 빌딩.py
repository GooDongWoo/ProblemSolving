import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    h, l = map(int, input().split())
    mat = [list(map(int, input().split())) for _ in range(h)]
    
    ordered_l = [[-1, -1] for _ in range((h * l))] 
    for i in range(h):
        for j in range(l):
            if mat[i][j] == -1:continue
            ordered_l[mat[i][j] -1] = [i, j]
    
    cur_idx = [0]*h
    timer = 0
    for i in range(len(ordered_l)):
        if ordered_l[i] == [-1, -1]: break
        y, x = ordered_l[i]
        timer += 5 * (min(abs(cur_idx[y]-x), abs(l-abs(cur_idx[y]-x))))
        cur_idx[y] = x
        timer += 20* (y)
    print(timer)