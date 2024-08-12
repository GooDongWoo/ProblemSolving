n=int(input())
seq=[*map(int,input().split())]
max1=max(seq)
if(max1>0):
    dp=[0]*n
    dp[0]=max(seq[0],0)
    for i in range(1,n):
        dp[i]=max(seq[i]+dp[i-1],0)
    print(max(dp))
else:
    print(max1)