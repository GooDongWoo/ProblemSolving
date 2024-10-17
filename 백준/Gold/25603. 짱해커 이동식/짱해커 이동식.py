import sys
input = sys.stdin.readline
n,k=map(int,input().split())
l=list(map(int,input().split()))
start=1
end=int(1e9)
def F(mid):
    global l,n,k
    idx=-1
    for i in range(n):
        if(l[i]<=mid):idx=i
        else:
            if((i-idx)>=k):return 0
    return 1

while start<=end:
    mid=(start+end)//2
    if(F(mid)):end=mid-1
    else:start=mid+1

print(start)