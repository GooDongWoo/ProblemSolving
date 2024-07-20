import sys
n,m=map(int,sys.stdin.readline().split())
inf=int(1e5)
setv=inf
singlev=inf
for i in range(m):
    t1,t2=map(int,sys.stdin.readline().split())
    setv,singlev=min(t1,setv),min(singlev,t2)

cost1=0
cost1+=(n//6)*setv
cost1+=(n%6)*singlev

cost2=0
cost2+=(n//6 +1)*setv

cost3=0
cost3+=n*singlev
print(min(cost1,cost2,cost3))