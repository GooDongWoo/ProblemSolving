import sys
from collections import deque
n,m,k=map(int,sys.stdin.readline().split())
added_nut=[list(map(int,input().split())) for _ in range(n)]
trees=[[deque() for _ in range(n)] for _ in range(n)]
cur_nutri=[[5]*n for _ in range(n)]
dys=[1,1,0,-1,-1,-1,0,1]
dxs=[0,1,1,1,0,-1,-1,-1]

xyzs=[tuple(map(int,sys.stdin.readline().split())) for _ in range(m)]
xyzs.sort(key=lambda x:x[2])
for x,y,z in xyzs:
    trees[x-1][y-1].append(z)

def spring():
    global n,m,k,added_nut,trees,cur_nutri,dys,dxs
    for i in range(n):
        for j in range(n):
            poor_flag=0
            poor_idx=0
            if(trees[i][j]):
                #spring
                for idx in range(len(trees[i][j])):
                    if(cur_nutri[i][j]-trees[i][j][idx]>=0):
                        cur_nutri[i][j]-=trees[i][j][idx]
                        trees[i][j][idx]+=1
                    else:
                        poor_flag=1
                        poor_idx=idx
                        break
                #summer
                if(poor_flag):
                    tmp1=len(trees[i][j])
                    for _ in range(tmp1 - poor_idx):
                        cur_nutri[i][j]+=(trees[i][j].pop())//2

def autumn():
    global n,m,k,added_nut,trees,cur_nutri,dys,dxs
    for i in range(n):
        for j in range(n):
            if(trees[i][j]):
                for each_t in (trees[i][j]):
                    if each_t%5==0:
                        for dy,dx in zip(dys,dxs):
                            ny,nx=dy+i,dx+j
                            if(0<=ny<n and 0<=nx<n):
                                trees[ny][nx].appendleft(1)

def winter():
    global n,m,k,added_nut,trees,cur_nutri,dys,dx
    for i in range(n):
        for j in range(n):
            cur_nutri[i][j]+=added_nut[i][j]

for _ in range(k):
    spring()
    autumn()
    winter()

cnt=0
for i in range(n):
    for j in range(n):
        cnt+=len(trees[i][j])
print(cnt)