import sys
from bisect import bisect_right as bisect
input=sys.stdin.readline
t=int(input())
for _ in range(t):
    tmp=list(map(int,input().split()))
    n=tmp[0]
    l=sorted(tmp[1:])
    avg=sum(l)/n
    sn=bisect(l,avg)
    sys.stdout.write(f'{100-sn/n*100:.3f}%\n')