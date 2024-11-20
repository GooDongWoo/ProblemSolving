import sys
from bisect import bisect_left as bl
input=sys.stdin.readline

n,m=map(int,input().split())
a=sorted([int(input()) for _ in range(n)])
candidates=[]
for i in range(n):
    target=a[i]+m
    target_idx=bl(a,target)
    if target_idx<n:
        candidate=a[target_idx]
        candidates.append(candidate-a[i])
    else:continue
print(min(candidates))