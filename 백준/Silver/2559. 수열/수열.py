import sys
input=sys.stdin.readline
n,k=map(int,input().split())
a=list(map(int,input().split()))

p=[0]*(n+1)
for i in range(n):
    p[i+1]=p[i]+a[i]
res=[]
for i in range(n-k+1):
    res.append(p[i+k]-p[i])
print(max(res))