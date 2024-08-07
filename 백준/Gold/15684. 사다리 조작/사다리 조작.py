from collections import deque
from itertools import combinations as cb
def combi(n:int,k:int)->list:
    if(k>n): return False
    result=[]
    t=deque()
    def comb(lastidx):
        nonlocal t
        if(len(t)==k):
            result.append(list(t).copy())
        else:
            for i in range(lastidx+1,n):
                t.append(i);comb(i);t.pop()
    comb(-1)
    return result

def simul()-> bool:
    global n,h,mat
    result=[i for i in range(n)]
    for i in range(h):
        for j in range(n-1):
            if(mat[i][j]):
                result[j],result[j+1]=result[j+1],result[j]
    return all([result[i]==i for i in range(n)])

def chckincs(l1:list)->bool:
    global neigh
    for y,x in l1:
        if(any([((ny,nx) in l1) for ny,nx in neigh[y][x]])):return 1
    return 0
    
n,m,h=map(int,input().split())
mat=[[0]*(n-1) for _ in range(h)]

horizon_lines=[]
for _ in range(m):
    a,b=map(int,input().split())
    mat[a-1][b-1]=1
    horizon_lines.append((a-1,b-1))

neigh=[[[] for _ in range(n-1)] for _ in range(h)]
for i in range(h):
    for j in range(n-1):
        for dx in [1,-1]:
            nj=j+dx
            if(0<=nj<n-1):neigh[i][j].append((i,nj))

candidates=[]
for i in range(h):
    for j in range(n-1):
        if((mat[i][j]==0) and (not any([mat[ni][nj]==1 for ni,nj in neigh[i][j]]))):
            candidates.append((i,j))

if(simul()):
    print(0)
    exit()

length=len(candidates)
if(length>=1):
    q1=[[candidates[i[0]]] for i in combi(length,1)]
    for cs in q1:
        for i,j in cs:
            mat[i][j]=1
        if(simul()):
            print(1)
            exit()
        for i,j in cs:
            mat[i][j]=0

if(length>=2):
    q2=[[candidates[i[0]],candidates[i[1]]] for i in combi(length,2)]
    for cs in q2:
        #cs안에서 하면안되는 경우 체크
        if(chckincs(cs)): 
            continue
        for i,j in cs:
            mat[i][j]=1
        if(simul()):
            print(2)
            exit()
        for i,j in cs:
            mat[i][j]=0

if(length>=3):                
    q3=[[candidates[i[0]],candidates[i[1]],candidates[i[2]]] for i in combi(length,3)]
    for cs in q3:
        #cs안에서 하면안되는 경우 체크
        if(chckincs(cs)): 
            continue
        for i,j in cs:
            mat[i][j]=1
        if(simul()):
            print(3)
            exit()
        for i,j in cs:
            mat[i][j]=0

print(-1)