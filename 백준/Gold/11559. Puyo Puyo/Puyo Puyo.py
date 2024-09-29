import sys
from collections import deque
input=sys.stdin.readline
mat=[list(input().rstrip()) for _ in range(12)]

def falling():
    for j in range(6):
        vl=[]
        for i in range(12):
            if(mat[i][j]!='.'):
                vl.append(mat[i][j])
                mat[i][j]='.'
        idx=11
        while vl:
            mat[idx][j]=vl.pop()
            idx-=1

def bfs(y,x):
    if(mat[y][x]=='.'): return False
    v=[[0]*6 for _ in range(12)]
    l=[]
    q=deque()
    target=mat[y][x]
    q.append((y,x))
    v[y][x]=1
    l.append((y,x))
    while q:
        y,x=q.popleft()
        for dy,dx in [(1,0),(0,1),(-1,0),(0,-1)]:
            ny,nx=y+dy,x+dx
            if(0<=ny<12 and 0<=nx<6 and mat[ny][nx]==target and v[ny][nx]==0):
                q.append((ny,nx))
                v[ny][nx]=1
                l.append((ny,nx))
    if(len(l)<4):
        return False
    else:
        for y,x in l:
            mat[y][x]='.'
        return True

def bomb():
    global score
    flag=False
    for i in range(12):
        for j in range(6):
            flag= bfs(i,j) or flag
    score+=flag
    return flag
            
score=0
while bomb():
    falling()

print(score)