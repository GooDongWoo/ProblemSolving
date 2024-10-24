import sys
from math import gcd
input = sys.stdin.readline
t=int(input())
MOD=1000000007
for _ in range(t):
    n=int(input())
    l=list(map(int,input().split()))
    res=1
    for i in range(n):
        res=((res*l[i])//gcd(res,l[i]))
    sys.stdout.write(f'{res%MOD}\n')