import sys
from bisect import bisect_right
import math
n=int(sys.stdin.readline())
limits=sorted([*map(int,sys.stdin.readline().split())])
m=int(sys.stdin.readline())
items=sorted([*map(int,sys.stdin.readline().split())])

loadings=[0]*n
for i in range(n):
    loadings[i]=(bisect_right(items,limits[i]))

if(loadings[-1]<m):
    print(-1)
    exit()

cnter=[0]*n
cnter[0]=loadings[0]
for i in range(1,n):
    cnter[i]=loadings[i]-loadings[i-1]

t_sum=0
max_time=0
for i in range(n-1,-1,-1):
    t_sum+=cnter[i]
    max_time=max(max_time,math.ceil(t_sum/(n-i)))
    
print(max_time)
'''tmp=cnter.index(max(cnter))
print(math.ceil(sum(cnter[tmp:])/(n-tmp)))'''