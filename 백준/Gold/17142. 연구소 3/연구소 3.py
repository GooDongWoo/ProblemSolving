from collections import deque
import sys
n,m=map(int,sys.stdin.readline().split())
mat=[list(map(int,sys.stdin.readline().split())) for _ in range(n)]
dys=[1,0,-1,0]
dxs=[0,1,0,-1]
vs=[]
cleancnt=0
for i in range(n):
    for j in range(n):
        if(mat[i][j]==2):
            vs.append((i,j))
        elif(mat[i][j]==0):
            cleancnt+=1

def combi(l1,k):#l1에서 k개를 선택한 case들을 모은 리스트
    length=len(l1)
    if(k>length):
        return -1
    result=[]
    tmp=[]
    def comb(last1):
        nonlocal k,length,l1
        if(len(tmp)==k):
            result.append(tmp.copy())
        else:
            for i in range(last1+1,length):
                tmp.append(l1[i])
                comb(i)
                tmp.pop()
    comb(-1)
    return result

def spread(starts:list):
    global n,m,mat,dys,dxs,cleancnt
    v=[[0]*n for _ in range(n)]
    q=deque()
    cleanarea=cleancnt
    for y,x in starts:
        v[y][x]=1
        q.append((y,x))
    cnt=0
    while q:
        if(cleanarea<=0): return cnt
        tt=len(q)
        cnt+=1
        for _ in range(tt):
            p=q.popleft()
            for dy,dx in zip(dys,dxs):
                ny,nx=dy+p[0],dx+p[1]
                if(0<=ny<n and 0<=nx<n and v[ny][nx]==0 and mat[ny][nx]!=1):
                    q.append((ny,nx))
                    v[ny][nx]=1
                    if(mat[ny][nx]==0):
                        cleanarea-=1
    return -1

cases=combi(vs,m)
candidates=set()
for case in cases:
    candidates.add(spread(case))
if(len(candidates)==1 and (-1 in candidates)):
    sys.stdout.write(f'-1\n')
else:
    candidates.discard(-1)
    sys.stdout.write(f'{min(list(candidates))}\n')