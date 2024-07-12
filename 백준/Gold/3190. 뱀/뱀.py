import sys
sys.setrecursionlimit(int(1e8))
from collections import deque
n=int(input())
mat=[[0]*n for _ in range(n)]
body_d=dict()
for i in range(n):
    for j in range(n):
        body_d[(i,j)]=0
body_d[(0,0)]=1

k=int(input())
for _ in range(k):
    row,col=map(int,input().split())
    mat[row-1][col-1]=1

l=int(input())
commands=deque([tuple(input().split()) for _ in range(l)]) #TODO 만약 시간 길다 싶으면 정렬 없애기

d=[(1,0),(0,1),(-1,0),(0,-1)]#남동북서-> 계속 왼쪽 방향 회전
d_d=dict([('L',1),('D',-1)]) #왼쪽이면 현재 d idx에서 1만큼 증가

time=-1# time variable

body=deque([(0,0)])

def game(r=0,c=0,d_idx=1):
    global n,mat,commands,d,d_d,time
    time+=1
    if(commands and int(commands[0][0])==time):
        d_idx=(d_idx+d_d[commands.popleft()[1]])%4

    r+=d[d_idx][0]
    c+=d[d_idx][1]

    if(0<=r<n and 0<=c<n and body_d[(r,c)]==0):#살았다. 이동한 값이 경계 안이고 몸이 아니다.add()
        #이동한 값이 사과
        if(mat[r][c]):
            mat[r][c]=0
            #사과이면 머리 위치를 appendleft()
            body.appendleft((r,c))
            body_d[(r,c)]=1
        
        #이동한 값이 사과 아님
        else:
            #머리 위치를 appendleft()
            body.appendleft((r,c))
            body_d[(r,c)]=1
            #꼬리를 pop()
            tail=body.pop()
            body_d[(tail[0],tail[1])]=0
        return game(r,c,d_idx)

    else:#사망
        print(time+1)
        return
game()