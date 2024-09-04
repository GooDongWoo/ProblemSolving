import sys
def dist(d1,d2):
    return (d1[0]-d2[0])**2+(d1[1]-d2[1])**2

def dotprod(std,d1,d2):
    x1,y1=d1[0]-std[0],d1[1]-std[1]
    x2,y2=d2[0]-std[0],d2[1]-std[1]    
    return x1*x2+y1*y2

def getMid(d1,d2):
    return (d1[0]+d2[0])//2,(d1[1]+d2[1])//2
t=int(sys.stdin.readline())
for _ in range(t):
    dots=[tuple(map(int,sys.stdin.readline().split())) for _ in range(4)]
    std_d=dots[0]
    dists=sorted([(dist(std_d,dots[i]),i) for i in range(1,4)])
    if(dists[0][0]==dists[1][0] and dotprod(std_d,dots[dists[0][1]],dots[dists[1][1]])==0 and getMid(dots[dists[0][1]],dots[dists[1][1]])==getMid(std_d,dots[dists[2][1]])):
        sys.stdout.write("1\n")
    else:
        sys.stdout.write("0\n")