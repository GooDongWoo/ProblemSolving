import sys
p=[list(map(int,sys.stdin.readline().split())) for _ in range(3)]
x1=p[1][0]-p[0][0]
y1=p[1][1]-p[0][1]
x2=p[2][0]-p[1][0]
y2=p[2][1]-p[1][1]

if ((x1*y2)-(y1*x2))<0:
    print(-1)
elif((x1*y2)-(y1*x2))==0:
    print(0)
else:
    print(1)