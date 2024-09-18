n=int(input())
ans_mat=[list(input().rstrip()) for _ in range(n)]
chck_mat=[list(input().rstrip()) for _ in range(n)]
cnter_mat=[[0]*n for _ in range(n)]
bomb_list=[]
dy_dx=[(1,0),(1,1),(0,1),(-1,1),(-1,0),(-1,-1),(0,-1),(1,-1)]
for i in range(n):
    for j in range(n):
        if(ans_mat[i][j]=='*'):
            bomb_list.append((i,j))
            cnter_mat[i][j]='*'
        else:
            for dy,dx in dy_dx:
                ny,nx=i+dy,j+dx
                if(0<=ny<n and 0<=nx<n and ans_mat[ny][nx]=='*'):
                    cnter_mat[i][j]+=1

submit_mat=[['.']*n for _ in range(n)]

for i in range(n):
    for j in range(n):
        if(chck_mat[i][j]=='x'):
            if(cnter_mat[i][j]=='*'):
                for y,x in bomb_list:
                    submit_mat[y][x]=cnter_mat[y][x]
            else:
                submit_mat[i][j]=cnter_mat[i][j]
for i in submit_mat:
    print(*i,sep='')