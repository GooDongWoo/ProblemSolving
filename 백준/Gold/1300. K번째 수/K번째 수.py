import sys
input=sys.stdin.readline
n=int(input())
k=int(input())

def F(row,target,n):
    start=1;end=n
    while start<=end:
        mid=(start+end)//2
        if mid*row<=target:
            start=mid+1
        else:
            end=mid-1
    return end #target보다 작거나 같은 수의 개수

start=1;end=int(1e10)
while start<=end:
    mid=(start+end)//2
    cnt=0
    for i in range(1,n+1):
        cnt+=F(i,mid,n)
    if cnt<k:
        start=mid+1
    else:
        end=mid-1
print(start)