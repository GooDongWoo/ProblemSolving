import sys
input=sys.stdin.readline

n,m,k=map(int,input().split())

mat=[list(input().rstrip()) for _ in range(n)]
dp=[[0]*(m+1) for _ in range(n+1)]

for i in range(1,n+1):
    for j in range(1,m+1):
        added=0 if ((i+j)%2==0 and mat[i-1][j-1]=="B") or ((i+j)%2!=0 and mat[i-1][j-1]=="W") else 1
        dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+added

res=[]
for i in range(k,n+1):
    for j in range(k,m+1):
        tmp=dp[i][j]-dp[i-k][j]-dp[i][j-k]+dp[i-k][j-k]
        res.append(tmp)
        res.append(k**2 -tmp)
print(min(res))