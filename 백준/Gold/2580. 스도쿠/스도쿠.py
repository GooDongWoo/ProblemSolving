import sys
input=sys.stdin.readline
n=9
mat=[list(map(int,input().split())) for _ in range(n)]

blanks=[]
for i in range(n):
    for j in range(n):
        if(mat[i][j]==0):
            blanks.append((i,j))

def candidatesMake(row,col):
    global mat,n
    srow=set([i for i in range(1,10)])
    scol=set([i for i in range(1,10)])
    smini=set([i for i in range(1,10)])
    
    for i in range(n):
        scol.discard(mat[row][i])
    
    for i in range(n):
        srow.discard(mat[i][col])
        
    minirow=row//3
    minicol=col//3
    for i in range(3):
        for j in range(3):
            smini.discard(mat[3*minirow+i][3*minicol+j])
            
    res=smini&scol&srow
    return res

def bt(idx):
    global blanks,n
    if idx==len(blanks):
        for i in range(n):
            print(*mat[i])
        exit(0)
    else:
        y,x=blanks[idx]
        candidates=candidatesMake(y,x)
        for target in candidates:
            mat[y][x]=target
            bt(idx+1)
            mat[y][x]=0

bt(0)