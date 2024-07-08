import sys
def dist(x1,y1,x2,y2):
    return (((x1-x2)**2)+((y1-y2)**2))**(1/2)
dots=list(map(int,sys.stdin.readline().split()))

if((dots[1]-dots[3])*(dots[4]-dots[2])==(dots[5]-dots[3])*(dots[0]-dots[2])):
    print(-1.0)
else:
    dists=[]
    for i in range(2):
        for j in range(i+1,3):
            dists.append(dist(dots[2*i],dots[2*i+1],dots[2*j],dots[2*j+1]))
    s=sum(dists)
    res=[]
    res.append(2*(s-dists[0]))
    res.append(2*(s-dists[1]))
    res.append(2*(s-dists[2]))
    print(max(res)-min(res))
