import sys
input=sys.stdin.readline
n=int(input())
x=0
y=0
xx=0
xy=0
for i in range(n):
    a,b=map(int,input().split())
    x+=a
    y+=b
    xx+=a**2
    xy+=a*b

if(n*xx==x**2):
    print("EZPZ")
else:
    a=(n*xy -x*y)/(n*xx - (x**2))
    b=(y-a*x)/(n)
    print(a,b)