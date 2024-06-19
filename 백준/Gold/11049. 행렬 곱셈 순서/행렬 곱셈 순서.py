import sys
N = int(sys.stdin.readline())
mat_list = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
dp_mat = [[0 for _ in range(N)] for _ in range(N)]
for diag in range(1, N):
    for start in range(N-diag):
        dp_mat[start][start+diag] = int(1e9)
        for t in range(start, start+diag):
            dp_mat[start][start+diag] = min(dp_mat[start][start+diag],dp_mat[start][t]+dp_mat[t+1][start+diag] + mat_list[start][0] * mat_list[t][1] * mat_list[start+diag][1])
sys.stdout.write(f'{dp_mat[0][N-1]}')