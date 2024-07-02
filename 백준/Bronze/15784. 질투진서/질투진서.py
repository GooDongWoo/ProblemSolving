import sys
n,a,b=map(int,sys.stdin.readline().split())
map_mat=[list(map(int,sys.stdin.readline().split())) for _ in range(n)]
flag=0
if(n>1):
    for i in range(n):
        if(map_mat[a-1][b-1]<map_mat[a-1][i] or map_mat[a-1][b-1]<map_mat[i][b-1]):
            flag=1
            break
if(flag):
    print('ANGRY')
else:
    print('HAPPY')