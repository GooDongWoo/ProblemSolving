import sys
from math import gcd
from bisect import bisect_right as bisect
input=sys.stdin.readline
n,m=map(int,input().split())
d=dict()# sign,x,y: y
#list
for _ in range(n):
    x,y=map(int,input().split())
    if(x==0):
        if((0,y//abs(y)) in d):
            d[(0,y//abs(y))].append(abs(y))
        else:
            d[(0,y//abs(y))]=[abs(y)]

    elif(y==0):
        if((x//abs(x),0) in d):
            d[(x//abs(x),0)].append(abs(x))
        else:
            d[(x//abs(x),0)]=[abs(x)]

    else:
        gcd_v=gcd(x,y)
        nx,ny=x//gcd_v,y//gcd_v
        if((nx,ny) in d):
            d[(nx,ny)].append(gcd_v)
        else:
            d[(nx,ny)]=[gcd_v]

for k in d.keys():
    d[k]=sorted(d[k])

#querys
rl=[]
for _ in range(m):
    x,y=map(int,input().split())
    if(x==0):
        gcd_v=abs(y)
        nx,ny=x//gcd_v,y//gcd_v
    elif(y==0):
        gcd_v=abs(x)
        nx,ny=x//gcd_v,y//gcd_v
    else:
        gcd_v=gcd(x,y)
        nx,ny=x//gcd_v,y//gcd_v
    
    if not ((nx,ny) in d):continue
    else:
        rl.append(bisect(d[(nx,ny)],gcd_v))
if(rl):
    print(max(rl))
else:
    print(0)