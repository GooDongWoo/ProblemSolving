from collections import deque
n,k=map(int,input().split())
a=deque(map(int,input().split()))
robots=deque([0]*(2*n))
zero_cnt=0

def rotate():
    global robots,a
    robots[n-1]=0
    robots.rotate(1)
    robots[n-1]=0
    a.rotate(1)

def move():
    global a,robots,zero_cnt
    for idx in range(n-2,0,-1):
        if(robots[idx]!=0 and robots[idx+1]==0 and a[idx+1]>0):
            robots[idx]=0
            robots[idx+1]=1
            a[idx+1]-=1
            if(a[idx+1]==0): zero_cnt+=1

def load():
    global zero_cnt
    if(a[0]!=0):
        robots[0]=1
        a[0]-=1
        if(a[0]==0): zero_cnt+=1

def zeroCnting():
    tmp=0
    for item in a:
        if(item==0): tmp+=1
    
    return tmp

level=0
while zero_cnt<k:
    level+=1
    rotate()
    move()
    load()

print(level)