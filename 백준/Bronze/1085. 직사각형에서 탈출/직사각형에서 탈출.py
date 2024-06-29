import sys
x,y,w,h=map(int,sys.stdin.readline().split())
if(0<=x<=w or 0<=y<=h):
    if(0<=x<=w and 0<=y<=h):
        dist=min(abs(y),abs(y-h),abs(x),abs(x-w))
    elif(0<=x<=w):
        dist=min(abs(y),abs(y-h))
    else:
        dist=min(abs(x),abs(x-w))
else:
    dist=(min(abs(x),abs(x-w))**2 + min(abs(y),abs(y-h))**2)**(1/2)
print(dist)