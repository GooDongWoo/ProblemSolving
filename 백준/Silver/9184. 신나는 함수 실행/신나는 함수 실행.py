import sys
input=sys.stdin.readline

dp=[[[1]*(101) for _ in range(101)] for _ in range(101)]

for i in range(51,71):
    for j in range(51,71):
        for k in range(51,71):
            if(i<j<k):
                dp[i][j][k]=dp[i][j][k-1]+dp[i][j-1][k-1]-dp[i][j-1][k]
            else:
                dp[i][j][k]=dp[i-1][j][k]+dp[i-1][j-1][k]+dp[i-1][j][k-1]-dp[i-1][j-1][k-1]

while True:
    a,b,c=map(int,input().split())
    if a==-1 and b==-1 and c==-1:break
    if a<=0 or b<=0 or c<=0:
        print(f'w({a}, {b}, {c}) = 1')
    elif a>20 or b>20 or c>20:
        print(f'w({a}, {b}, {c}) = {dp[70][70][70]}')
    else:
        print(f'w({a}, {b}, {c}) = {dp[a+50][b+50][c+50]}')