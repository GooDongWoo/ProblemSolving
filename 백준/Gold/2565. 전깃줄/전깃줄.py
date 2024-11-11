import sys
input=sys.stdin.readline
n = int(input())
ll=sorted([list(map(int, input().split())) for _ in range(n)])
dp=[0]*n
dp[0]=1

for i in range(1,n):
    tmpLIS=[]
    
    for j in range(i):
        if(ll[j][1]<ll[i][1]):
            tmpLIS.append(ll[j][1])
    tmpLIS.append(ll[i][1])
    
    minilen=len(tmpLIS)
    minidp=[1]*minilen
    
    for j in range(1,minilen):
        for k in range(j):
            if(tmpLIS[j]>tmpLIS[k]):
                minidp[j]=max(minidp[j],minidp[k]+1)

    result=max(minidp)
    dp[i]=max(dp[i-1],result)
print(n-dp[-1])