import sys
n=int(sys.stdin.readline())
inf=int(1e8)
cList=[]
for _ in range(n):
    cList.append(tuple(map(int,sys.stdin.readline().split())))
    
r_dp=[(cList[0][0],inf,inf)]
g_dp=[(inf,cList[0][1],inf)]
b_dp=[(inf,inf,cList[0][2])]

r_dp.append((inf,cList[1][1]+r_dp[0][0],cList[1][2]+r_dp[0][0]))
g_dp.append((cList[1][0]+g_dp[0][1],inf,cList[1][2]+g_dp[0][1]))
b_dp.append((cList[1][0]+b_dp[0][2],cList[1][1]+b_dp[0][2],inf))

for i in range(2,n):
    r_dp.append((cList[i][0]+min(r_dp[i-1][1],r_dp[i-1][2]),\
                cList[i][1]+min(r_dp[i-1][0],r_dp[i-1][2]),\
                cList[i][2]+min(r_dp[i-1][0],r_dp[i-1][1])))
    
    g_dp.append((cList[i][0]+min(g_dp[i-1][1],g_dp[i-1][2]),\
                cList[i][1]+min(g_dp[i-1][0],g_dp[i-1][2]),\
                cList[i][2]+min(g_dp[i-1][0],g_dp[i-1][1])))
    
    b_dp.append((cList[i][0]+min(b_dp[i-1][1],b_dp[i-1][2]),\
                cList[i][1]+min(b_dp[i-1][0],b_dp[i-1][2]),\
                cList[i][2]+min(b_dp[i-1][0],b_dp[i-1][1])))

print(min(list(r_dp[-1][1:])+list(g_dp[-1][::2])+list(b_dp[-1][:-1])))