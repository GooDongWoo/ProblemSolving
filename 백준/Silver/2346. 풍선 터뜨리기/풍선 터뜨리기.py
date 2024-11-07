import sys
from collections import deque
input=sys.stdin.readline

n=int(input())
origin=[*map(int,input().split())]
deq=deque([(i+1,origin[i]) for i in range(n)])
res=[]
while deq:
    num,incre=deq.popleft()
    incre= incre-1 if incre>0 else incre
    res.append(num)
    deq.rotate(-incre)
print(*res)