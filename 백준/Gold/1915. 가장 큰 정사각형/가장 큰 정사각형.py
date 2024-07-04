import sys
n,m=map(int,sys.stdin.readline().split())
map_mat=[list(map(int,list(sys.stdin.readline().rstrip()))) for _ in range(n)]
dp=[[[0]*3 for _ in range(m+1)] for _ in range(n+1)]
max_length=0
for i in range(1,(n)+1):
    for j in range(1,(m)+1):
        if(map_mat[i-1][j-1]):
            dp[i][j][0],dp[i][j][1]= dp[i-1][j][0]+1,dp[i][j-1][1]+1 #행,열
            if(dp[i-1][j-1][2]>0):
                if(dp[i-1][j-1][2]<dp[i][j][0] and dp[i-1][j-1][2]<dp[i][j][1]):
                    dp[i][j][2]=dp[i-1][j-1][2]+1
                else:
                    dp[i][j][2]=min(dp[i][j][0],dp[i][j][1])
            else:
                dp[i][j][2]=1
            max_length=max(max_length,dp[i][j][2])
sys.stdout.write(f'{max_length**2}')