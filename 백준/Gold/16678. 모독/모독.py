import sys
input = sys.stdin.readline
n=int(input())
l=sorted([int(input()) for _ in range(n)])
cnt=0
if(l[0]>1):
    cnt+=l[0]-1
    l[0]=1
for i in range(1,n):
    if(l[i]>l[i-1]+1):
        cnt+=l[i]-(l[i-1]+1)
        l[i]=l[i-1]+1
print(cnt)