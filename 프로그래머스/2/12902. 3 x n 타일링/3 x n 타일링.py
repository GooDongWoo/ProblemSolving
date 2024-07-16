def solution(n):
    if(n&1):
        return 0
    dp=[0]*(n+1)
    dp[2]=3
    if(n>2):
        dp[4]=11
        s=3
        for i in range(6,n+1,2):
            dp[i]=((dp[i-2]*3)+s*2+2)%1000000007
            s+=dp[i-2]
    return dp[n]