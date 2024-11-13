import sys
from math import lcm
input=sys.stdin.readline

n,k=map(int,input().split())
a=list(map(int,input().split()))
lcm1=lcm(n,k)
each_len=lcm1//k
candidates=[[] for _ in range(n//each_len)]
for i in range(n//each_len):
    for j in range(each_len):
        candidates[i].append(a[(i+(j*k))%n])

print(max([sum(i) for i in candidates]))