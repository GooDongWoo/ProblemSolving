import sys
input=sys.stdin.readline
n=int(input())
ss=[*map(int,input().split())]
k=int(input())
for i in range(k):
    a,b=map(int,input().split())
    if(a==1):
        for i in range(b,n+1,b):
            ss[i-1]^=1
    else:
        ss[b-1]^=1
        idx=1
        while (0<=b-1-idx<n and 0<=b-1+idx<n and ss[b-1-idx]==ss[b-1+idx]):
            ss[b-1-idx]^=1
            ss[b-1+idx]^=1
            idx+=1
idx=0
while idx<n:
    if(idx%20==0 and idx!=0):print()
    print(ss[idx],end=' ')
    idx+=1