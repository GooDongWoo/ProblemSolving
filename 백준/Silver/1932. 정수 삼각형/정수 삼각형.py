import sys
n=int(input())
cost_list=[[0 for _ in range(n)] for _ in range(n)]
dp_list=[[0 for _ in range(n)] for _ in range(n)]
for i in range(n):
    for idx,j in enumerate(list(map(int,sys.stdin.readline().split()))):
        cost_list[i][idx]= j

dp_list[0]=cost_list[0]
#make dp-mat
for i in range(1,n):
    for j in range(n):
        if(j>0):
            dp_list[i][j]=max(dp_list[i-1][j-1]+cost_list[i][j],dp_list[i-1][j]+cost_list[i][j])
        else:
            dp_list[i][j]=dp_list[i-1][j]+cost_list[i][j]

print(max(dp_list[-1]))