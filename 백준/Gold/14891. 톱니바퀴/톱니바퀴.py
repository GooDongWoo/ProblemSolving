import sys
from collections import deque
cls=[deque([*map(int,[*(sys.stdin.readline().rstrip())])]) for _ in range(4)] #N:0, S:1
m=[0 for _ in range(4-1)]


k=int(sys.stdin.readline())
for _ in range(k):
    #톱니 방향 극성 체크
    for i in range(4-1):
        m[i]= 0 if(cls[i][2]==cls[i+1][6]) else -1
    num,cw=map(int,sys.stdin.readline().split())#cw:1,ccw:-1
    num-=1
    #본인 회전
    cls[num].rotate(cw)
    #왼쪽으로 회전 전파
    tmp=cw
    for i in range(num-1,-1,-1):
        tmp*=m[i]
        cls[i].rotate(tmp)
    
    tmp=cw
    #오른쪽으로 회전 전파
    for i in range(num+1,4):
        tmp*=m[i-1]
        cls[i].rotate(tmp)

score=0
for i in range(4):
    if(cls[i][0]==1):
        score+=2**i
print(score)