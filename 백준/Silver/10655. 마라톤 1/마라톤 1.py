import sys
n=int(sys.stdin.readline())
chckpoints=[tuple(map(int,sys.stdin.readline().split())) for _ in range(n)]

d=[0]*(n-1)
for i in range(n-1):
    d[i]=abs(chckpoints[i+1][0]-chckpoints[i][0])+abs(chckpoints[i+1][1]-chckpoints[i][1])

origin=sum(d)
min1=origin
for i in range(n-2):
    tmp=abs(chckpoints[i+2][0]-chckpoints[i][0])+abs(chckpoints[i+2][1]-chckpoints[i][1])
    min1=min(min1,origin-(d[i])-(d[i+1])+tmp)
print(min1)