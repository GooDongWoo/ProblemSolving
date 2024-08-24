from math import gcd

def solve():
    d1,d2=map(int,input().split())
    occupied=[[0]*(d2+1)for _ in range(d2+1)]
    ans=0
    for nth in range(d1,d2+1):
        for j in range(1,nth+1):
            res=gcd(j,nth)
            r,c=j//res,nth//res
            if(occupied[r][c]==0):
                occupied[r][c]=1
                ans+=1
    print(ans)

solve()