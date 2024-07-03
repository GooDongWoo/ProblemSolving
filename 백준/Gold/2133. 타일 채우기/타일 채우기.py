import sys
limit=30
N=int(sys.stdin.readline())
if N%2==1:
    print(0)
else:
    DP=[0]*(limit+1)
    DP[0]=1
    DP[1]=0
    DP[2]=3
    for i in range(4,N+1,2):
        DP[i]=DP[i-2]*DP[2]
        for j in range(i-4,-1,-2):
            DP[i]+=DP[j]*2
    print(DP[N])
