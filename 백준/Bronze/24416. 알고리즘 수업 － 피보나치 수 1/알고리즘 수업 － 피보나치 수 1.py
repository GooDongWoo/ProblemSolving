import sys
input=sys.stdin.readline
n=int(input())
a=[0]*(n+1)
a[1]=a[2]=1
for i in range(3,n+1):
    a[i]=a[i-1]+a[i-2]
print(a[n],n-2)