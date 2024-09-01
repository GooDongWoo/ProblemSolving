import sys
from collections import deque
n,k,t=map(int,sys.stdin.readline().split())
l1=deque(sorted(list(map(int,sys.stdin.readline().split()))))
while l1 and l1[0]==0:l1.popleft()
while t>0 and len(l1)>1:
    min1=l1.popleft()
    max1=l1.pop()
    if (min1+max1)>k:
        l1.appendleft((min1+max1)-k)
        t-=(k-max1)
    elif (min1+max1)==k:
        t-=min1
    else:
        l1.append(min1+max1)
        t-=min1
print('NO' if(l1 or t<0) else 'YES')