import sys
input=sys.stdin.readline
n=int(input())
querys=[tuple(map(int,input().split())) for _ in range(n)]

blue=[[0]*4 for _ in range(6)]
green=[[0]*4 for _ in range(6)]

score=0

def falling(t,r,c,mat):
    global score
    if(t==1):
        spots=[(0,c)]
    elif(t==2):
        spots=[(0,c),(0,c+1)]
    else:
        spots=[(0,c),(1,c)]
    h=1
    FLAG=0
    
    #Falling
    while h<6 and not FLAG:
        for y,x in spots:
            ny,nx=y+h,x
            if(ny<6 and mat[ny][nx]):
                FLAG=1
                break
        h+=1
    if(FLAG):
        for y,x in spots:
            ny,nx=y+h-2,x
            mat[ny][nx]=1
    else:
        if(t!=3):
            for _,x in spots:
                mat[5][x]=1
        else:
            mat[4][x]=1
            mat[5][x]=1
    #complete line delete and plus score
    cl=[i for i in range(len(mat)) if sum(mat[i])==4]
    if(cl):
        if len(cl)==2:
            i1=cl[0]
            mat[i1]=[0]*4
            mat[i1+1]=[0]*4
            for i in range(i1+1,1,-1):
                mat[i]=mat[i-2]
            mat[0:2]=[[0]*4 for _ in range(2)]
            score+=2
        else:
            i1=cl[0]
            mat[i1]=[0]*4
            for i in range(i1,0,-1):
                mat[i]=mat[i-1]
            mat[0]=[0]*4
            score+=1
    #if line exceed, copy and paste hight lines
    chck=[i for i in range(2) if(sum(mat[i]))]
    if(chck):
        if(len(chck)==2):
            mat[2:6]=mat[0:4]
            mat[0:2]=[[0]*4 for _ in range(2)]
        else:
            mat[2:6]=mat[1:5]
            mat[0:2]=[[0]*4 for _ in range(2)]
    return

for t,x,y in querys:
    if(t==1):
        new_t=1
    elif(t==2):
        new_t=3
    else:
        new_t=2
    falling(t,x,y,green)
    falling(new_t,y,x,blue)

result=0
for i in range(len(blue)):
    for j in range(len(blue[0])):
        if(blue[i][j]==1):result+=1
for i in range(len(green)):
    for j in range(len(green[0])):
        if(green[i][j]==1):result+=1
print(score)
print(result)