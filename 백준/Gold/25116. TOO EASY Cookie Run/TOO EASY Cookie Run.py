import sys
input=sys.stdin.readline

n,m,k=map(int,input().split())
l=list(map(int,input().split()))
prefix_sum=[0]*(n+1)
for i in range(1,n+1):
    prefix_sum[i]=prefix_sum[i-1]+l[i-1]

def F(added1):
    global n,m,k,prefix_sum
    cnt=0
    for lidx in range(0,n):
        start=lidx
        end=n
        while start<=end:
            mid=(start+end)//2
            if (prefix_sum[mid]-prefix_sum[lidx])+added1*(mid-lidx)>=m:
                end=mid-1
            else:start=mid+1
        
        cnt+=n-end
    return cnt
    

start=0;end=m
while start<=end:
    mid=(start+end)//2
    cnt=F(mid)
    if cnt>=k:
        end=mid-1
    else:
        start=mid+1
print(start)