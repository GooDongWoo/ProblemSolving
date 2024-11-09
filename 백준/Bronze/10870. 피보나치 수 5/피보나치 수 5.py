import sys
from collections import deque
input=sys.stdin.readline

n=int(input())
a=[0]*(21)
a[0]=0
a[1]=1
for i in range(2,n+1):
    a[i]=a[i-1]+a[i-2]
print(a[n])