import sys
from math import lcm,gcd

input=sys.stdin.readline
p1=[*map(int,input().split())]
p2=[*map(int,input().split())]

gcd1=gcd(p1[0],p1[1])
p1[0]//=gcd1;p1[1]//=gcd1

gcd2=gcd(p2[0],p2[1])
p2[0]//=gcd2;p2[1]//=gcd2

lcm1=lcm(p1[1],p2[1])
res=[0]*2
res[0]=p1[0]*(lcm1//p1[1])+p2[0]*(lcm1//p2[1])
res[1]=lcm1

gcd3=gcd(res[0],res[1])
res[0]//=gcd3;res[1]//=gcd3
print(*res)