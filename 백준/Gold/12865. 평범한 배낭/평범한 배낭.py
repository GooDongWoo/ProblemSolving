import sys
n,k=map(int,sys.stdin.readline().split())
items=[list(map(int,sys.stdin.readline().split())) for _ in range(n)]
dp_list=[[0 for _ in range(k+1)] for _ in range(n+1)]
for i in range(1,n+1):
    for j in range(1,k+1):
        if(j-items[i-1][0]>=0):
            dp_list[i][j]=max(dp_list[i-1][j],dp_list[i-1][j-items[i-1][0]]+items[i-1][1])
        else:
            dp_list[i][j]=dp_list[i-1][j]
print(dp_list[-1][-1])