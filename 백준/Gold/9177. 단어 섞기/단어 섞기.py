import sys
input=sys.stdin.readline
t=int(input())
for num in range(1,t+1):
    f,s,t=map(list,input().split())
    fl=len(f);sl=len(s)
    dp=[[0]*(fl+1) for _ in range(sl+1)]
    dp[0][0]=1
    for d in range(1,len(t)+1):
        for i in range(d+1):
            j=d-i
            if not (0<=i<(sl+1) and 0<=j<(fl+1)):continue
            if((dp[i-1][j]==1 and s[i-1]==t[d-1]) or (dp[i][j-1]==1 and f[j-1]==t[d-1])):
                dp[i][j]=1
    if(dp[-1][-1]):print(f"Data set {num}: yes")
    else:print(f"Data set {num}: no")