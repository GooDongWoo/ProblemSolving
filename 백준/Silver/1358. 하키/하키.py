import sys
w,h,x,y,p=map(int,sys.stdin.readline().split())
cnt=0
radius=h//2
def dist(x1,y1,x2,y2):
    return ((x1-x2)**2 + (y1-y2)**2)**(1/2)

for _ in range(p):
    a,b=map(int,sys.stdin.readline().split())
    if(x<=a<=x+w and y<=b<=y+h):
        cnt+=1
    elif(dist(a,b,x,y+radius)<=radius or dist(a,b,x+w,y+radius)<=radius):
        cnt+=1
print(cnt)