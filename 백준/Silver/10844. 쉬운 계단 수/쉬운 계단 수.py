import sys
from collections import deque
n=int(sys.stdin.readline())
dp_list=[[0 for _ in range(10)] for _ in range(n+1)]
dp_list[1]=[1]*10
dp_list[1][0]=0
for i in range(2,n+1):
    dp_list[i][0]=dp_list[i-1][1]
    for j in range(1,9):
        dp_list[i][j]=dp_list[i-1][j-1]+dp_list[i-1][j+1]
    dp_list[i][9]=dp_list[i-1][8]
sys.stdout.write(f'{sum(dp_list[-1])%1000000000}')